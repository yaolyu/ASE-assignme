/// @file NGLScene.cpp
/// @brief basic implementation file for the NGLScene class
#include "NGLScene.h"
#include <iostream>
#include <ngl/Light.h>
#include <ngl/Material.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <array>

#include <QDebug>
#include <QMouseEvent>
#include <ngl/Obj.h>
#include <ngl/VAOFactory.h>


const std::array<std::string,17> s_vboNames={
{
  "sphere",
  "cylinder",
  "cone",
  "disk",
  "plane",
  "torus",
  "teapot",
  "octahedron",
  "dodecahedron",
  "icosahedron",
  "tetrahedron",
  "football",
  "cube",
  "troll",
  "buddah",
  "dragon",
  "bunny"
  }
};

constexpr auto PhongShader="PhongShader";
constexpr auto NormalShader="normalShader";
constexpr auto ColourShader="nglColourShader";


//----------------------------------------------------------------------------------------------------------------------
NGLScene::NGLScene(QWidget *_parent )
{

  // set this widget to have the initial keyboard focus
  setFocus();
  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
  this->resize(_parent->size());
  m_drawIndex=6;
  m_drawNormals=false;
  /// set all our matrices to the identity
  m_transform=1.0f;
  m_rotate=1.0f;
  m_translate=1.0f;
  m_scale=1.0f;
  m_normalSize=6.0f;
  m_colour.set(0.5f,0.5f,0.5f);
  m_material.setDiffuse(m_colour);
  m_material.setSpecular(ngl::Colour(0.2f,0.5f,0.5f));
  m_material.setAmbient(ngl::Colour());
  m_material.setSpecularExponent(20.0f);
  m_material.setRoughness(0.0f);
  m_matrixOrder=NGLScene::MatrixOrder::RTS;
  m_euler=1.0f;
  m_modelPos.set(0.0f,0.0f,0.0f);

}

// This virtual function is called once before the first call to paintGL() or resizeGL(),
//and then once whenever the widget has been assigned a new QGLContext.
// This function should set up any required OpenGL context rendering flags, defining display lists, etc.

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::initializeGL()
{
  ngl::NGLInit::instance();

  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // Now we will create a basic Camera from the graphics library
  // This is a static camera so it only needs to be set once
  // First create Values for the camera position
  ngl::Vec3 from(0.0f,0.0f,8.0f);
  ngl::Vec3 to(0.0f,0.0f,0.0f);
  ngl::Vec3 up(0.0f,1.0f,0.0f);


  m_cam.set(from,to,up);
  // set the shape using FOV 45 Aspect Ratio based on Width and Height
  // The final two are near and far clipping planes of 0.5 and 10
  m_cam.setShape(45.0f,720.0f/576.0f,0.5f,10.0f);
  // now to load the shader and set the values
  // grab an instance of shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();

  // we are creating a shader called Phong
  shader->createShaderProgram(PhongShader);

  // now we are going to create empty shaders for Frag and Vert
  // use thes string to save typos
  constexpr auto vertexShader="PhongVertex";
  constexpr auto fragShader="PhongFragment";

  shader->attachShader(vertexShader,ngl::ShaderType::VERTEX);
  shader->attachShader(fragShader,ngl::ShaderType::FRAGMENT);
  // attach the source
  shader->loadShaderSource(vertexShader,"shaders/PhongVertex.glsl");
  shader->loadShaderSource(fragShader,"shaders/PhongFragment.glsl");
  // compile the shaders
  shader->compileShader(vertexShader);
  shader->compileShader(fragShader);
  // add them to the program
  shader->attachShaderToProgram(PhongShader,vertexShader);
  shader->attachShaderToProgram(PhongShader,fragShader);

  // now we have associated this data we can link the shader
  shader->linkProgramObject(PhongShader);
  // and make it active ready to load values
  (*shader)[PhongShader]->use();

  // now create our light this is done after the camera so we can pass the
  // transpose of the projection matrix to the light to do correct eye space
  // transformations
  ngl::Mat4 iv=m_cam.getProjectionMatrix();
  iv.transpose();
  ngl::Light light(ngl::Vec3(-2.0f,2.0f,-2.0f),ngl::Colour(1.0f,1.0f,1.0f,1.0f),ngl::Colour(1.0f,1.0f,1.0f,1.0f),ngl::LightModes::POINTLIGHT);
  light.setTransform(iv);
  // load these values to the shader as well
  light.loadToShader("light");



  // set the bg colour
  glClearColor(0.5,0.5,0.5,0.0);
  m_axis.reset( new Axis(ColourShader,1.5f));
  m_axis->setCam(
              &m_cam);
  // load the normal shader
  shader->createShaderProgram(NormalShader);
  constexpr auto normalVert="normalVertex";
  constexpr auto normalGeo="normalGeo";
  constexpr auto normalFrag="normalFrag";

  shader->attachShader(normalVert,ngl::ShaderType::VERTEX);
  shader->attachShader(normalFrag,ngl::ShaderType::FRAGMENT);
  shader->loadShaderSource(normalVert,"shaders/normalVertex.glsl");
  shader->loadShaderSource(normalFrag,"shaders/normalFragment.glsl");

  shader->compileShader(normalVert);
  shader->compileShader(normalFrag);
  shader->attachShaderToProgram(NormalShader,normalVert);
  shader->attachShaderToProgram(NormalShader,normalFrag);

  shader->attachShader(normalGeo,ngl::ShaderType::GEOMETRY);
  shader->loadShaderSource(normalGeo,"shaders/normalGeo.glsl");
  shader->compileShader(normalGeo);
  shader->attachShaderToProgram(NormalShader,normalGeo);

  shader->linkProgramObject(NormalShader);
  shader->use(NormalShader);
  // now pass the modelView and projection values to the shader
  shader->setUniform("normalSize",0.1f);
  shader->setUniform("vertNormalColour",1.0f,1.0f,0.0f,1.0f);
  shader->setUniform("faceNormalColour",1.0f,0.0f,0.0f,1.0f);

  shader->setShaderParam1i("drawFaceNormals",true);
  shader->setShaderParam1i("drawVertexNormals",true);
  shader->use("nglColourShader");
  shader->setUniform("Colour",1.0f,0.0f,0.0f,1.0f);

   //by yao 0108
  unsigned int index;
  vertex vert;
  ngl::Obj obj("character2_5000.obj");
  m_face=obj.getFaceList();
  m_nFaces=m_face.size();
  m_verts=obj.getVertexList();
  m_bone.judgeJointZone(m_verts);
  m_bone.initializeBone(m_verts,"Skeleton.tgf");
  m_vertsForAnimation=m_verts;
  m_bone.m_chainForAnimation=m_bone.m_chain;



  for(size_t i=0;i<m_nFaces;++i)
  {
      index=m_face[i].m_vert[0];
      vert.p.m_x=m_verts[index].m_x;vert.p.m_y=m_verts[index].m_y;vert.p.m_z=m_verts[index].m_z;
      m_data.push_back(vert);
      index=m_face[i].m_vert[1];
      vert.p.m_x=m_verts[index].m_x;vert.p.m_y=m_verts[index].m_y;vert.p.m_z=m_verts[index].m_z;
      m_data.push_back(vert);
      index=m_face[i].m_vert[2];
      vert.p.m_x=m_verts[index].m_x;vert.p.m_y=m_verts[index].m_y;vert.p.m_z=m_verts[index].m_z;
      m_data.push_back(vert);

  }

  for(size_t i=0;i<m_data.size();i+=3)
  {
      ngl::Vec3 normal=ngl::calcNormal(m_data[i+1].p,m_data[i].p,m_data[i+2].p);
      m_data[i].n=normal;
      m_data[i+1].n=normal;
      m_data[i+2].n=normal;
  }


  m_vao.reset(ngl::VAOFactory::createVAO(ngl::simpleVAO,GL_TRIANGLES));
  /*m_vao->bind();
  m_vao->setData(ngl::AbstractVAO::VertexData(m_data.size()*sizeof(vertex),
                                              m_data[0].p.m_x));
  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,sizeof(vertex),0);
  m_vao->setVertexAttributePointer(2,3,GL_FLOAT,sizeof(vertex),3);
  m_vao->setNumIndices(m_data.size());
  m_vao->unbind();
*/
    m_vao_bone.reset(ngl::VAOFactory::createVAO(ngl::simpleVAO,GL_LINE_STRIP));
    /*m_vao_bone->bind();
    m_vao_bone->setData(ngl::AbstractVAO::VertexData(sizeof(ngl::Vec3)*m_bone.m_chain.size(),
                                                m_bone.m_chain[0].m_x));
    m_vao_bone->setVertexAttributePointer(0,3,GL_FLOAT,sizeof(ngl::Vec3),0);
    //m_vao_bone->setVertexAttributePointer(1,3,GL_FLOAT,sizeof(ngl::Vec3),3);
    m_vao_bone->setNumIndices(m_bone.m_chain.size());
    m_vao_bone->unbind();
    //end
    */

  startTimer(20);

  //end 0116

}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget has been resized.
// The new size is passed in width and height.
void NGLScene::resizeGL(int _w, int _h )
{
  glViewport(0,0,_w,_h);
  m_cam.setShape(45.0f,static_cast<float>(_w)/_h,0.05f,450.0f);

}

void NGLScene::loadMatricesToShader( )
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)[PhongShader]->use();
  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 M;
  M=m_transform*m_mouseGlobalTX;
  MV=M*m_cam.getViewMatrix();
  MVP=  MV*m_cam.getProjectionMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMat4("MV",MV);
  shader->setShaderParamFromMat4("MVP",MVP);
  shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
  shader->setShaderParamFromMat4("M",M);
}





void NGLScene::timerEvent(QTimerEvent *)
{
  static float time;
  time-=0.1f;
  static size_t count;
  count++;
  m_data.clear();
  unsigned int index;
  vertex vert;

  float a=0;
  float a1=0;
  float a2=0;

   std::vector<float> angle;
   angle.push_back(a);
   angle.push_back(a1);
   angle.push_back(a2);
   float x_time=time;
   std::cout<<"Time is :"<<x_time<<std::endl;
    if(m_resetanimation==1)
   {
        m_vertsForAnimation=m_verts;
        m_bone.m_chainForAnimation=m_bone.m_chain;
        m_resetanimation=0;
    }
   //std::cout<<"animation"<<m_resetanimation<<std::endl;
   angle[0]-=(0.0f+m_sketeon_pace1);
   angle[1]-=(0.0f+m_sketeon_pace2);
   angle[2]-=(0.0f+m_sketeon_pace3);

  m_vertsForAnimation=m_bone.ApplyDeformation(m_vertsForAnimation,angle,m_elimination);
  for(size_t i=0;i<m_nFaces;++i)
  {
      index=m_face[i].m_vert[0];
      vert.p.m_x=m_vertsForAnimation[index].m_x;vert.p.m_y=m_vertsForAnimation[index].m_y;vert.p.m_z=m_vertsForAnimation[index].m_z;
      m_data.push_back(vert);
      index=m_face[i].m_vert[1];
      vert.p.m_x=m_vertsForAnimation[index].m_x;vert.p.m_y=m_vertsForAnimation[index].m_y;vert.p.m_z=m_vertsForAnimation[index].m_z;
      m_data.push_back(vert);
      index=m_face[i].m_vert[2];
      vert.p.m_x=m_vertsForAnimation[index].m_x;vert.p.m_y=m_vertsForAnimation[index].m_y;vert.p.m_z=m_vertsForAnimation[index].m_z;
      m_data.push_back(vert);

  }
  for(size_t i=0;i<m_data.size();i+=3)
  {
      ngl::Vec3 normal=ngl::calcNormal(m_data[i+1].p,m_data[i].p,m_data[i+2].p);
      m_data[i].n=normal;
      m_data[i+1].n=normal;
      m_data[i+2].n=normal;
  }

  update();

}



//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget needs to be painted.
// this is our main drawing routine
void NGLScene::paintGL()
{
   //I don't know why I can't throw memory of m_vao to ptr in timerEvent;
   //So use global parameter time and use it in deformVao()
   //modify the ptr here
   // deformVao();
  // grab an instance of the shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Rotation based on the mouse position for our global
  // transform
  m_transform.identity();

  if (m_matrixOrder == NGLScene::MatrixOrder::RTS)
  {
    m_transform=m_rotate*m_translate*m_scale;
  }

  else if (m_matrixOrder == NGLScene::MatrixOrder::TRS)
  {
    m_transform=m_translate*m_rotate*m_scale;
  }
  else if (m_matrixOrder == NGLScene::MatrixOrder::EULERTS)
  {
    m_transform=m_translate*m_euler*m_scale;
  }
  else if (m_matrixOrder == NGLScene::MatrixOrder::TEULERS)
  {
    m_transform=m_euler*m_translate*m_scale;
  }

  else if (m_matrixOrder == NGLScene::MatrixOrder::GIMBALLOCK )
  {
    m_transform=m_translate*m_gimbal*m_scale;
  }
  emit matrixDirty(m_transform);
  // now set this value in the shader for the current ModelMatrix
  (*shader)[PhongShader]->use();

  m_material.loadToShader("material");


  // Rotation based on the mouse position for our global transform
    ngl::Mat4 rotX;
    ngl::Mat4 rotY;
    // create the rotation matrices
    rotX.rotateX(m_win.spinXFace);
    rotY.rotateY(m_win.spinYFace);
    // multiply the rotations
    m_mouseGlobalTX=rotY*rotX;
    // add the translations
    m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
    m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
    m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;


    loadMatricesToShader();


    //ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
    if( m_wireframe)
    {
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else
    {
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }

    m_vao_bone->bind();
    m_vao_bone->setData(ngl::AbstractVAO::VertexData(m_bone.m_chainForAnimation.size()*sizeof(ngl::Vec3),
                                                m_bone.m_chainForAnimation[0].m_x));
    m_vao_bone->setVertexAttributePointer(0,3,GL_FLOAT,sizeof(ngl::Vec3),0);
    m_vao_bone->setNumIndices(m_bone.m_chainForAnimation.size());
    if(m_drawSkeletons)
    {
    m_vao_bone->draw();
    }
    m_vao_bone->unbind();
    std::cout<<"draw s"<<m_drawSkeletons<<std::endl;

    m_vao->bind();
    m_vao->setData(ngl::AbstractVAO::VertexData(m_data.size()*sizeof(vertex),
                                                m_data[0].p.m_x));
    m_vao->setVertexAttributePointer(0,3,GL_FLOAT,sizeof(vertex),0);
    m_vao->setVertexAttributePointer(2,3,GL_FLOAT,sizeof(vertex),3);
    m_vao->setNumIndices(m_data.size());
    if(m_drawSkeletons==0)
    {
        m_vao->draw();
    }
    m_vao->unbind();



    if(m_drawNormals)
    {

      (*shader)[NormalShader]->use();
      ngl::Mat4 MV;
      ngl::Mat4 MVP;

      MV=m_transform*m_mouseGlobalTX* m_cam.getViewMatrix();
      MVP=MV*m_cam.getProjectionMatrix();
      shader->setUniform("MVP",MVP);
      shader->setUniform("normalSize",m_normalSize/10.0f);
     //by yao 0116

      m_vao_bone->bind();
      m_vao_bone->draw();
      m_vao_bone->unbind();

      //end 0116
      //by yao 0108

      m_vao->bind();
      m_vao->setData(ngl::AbstractVAO::VertexData(m_data.size()*sizeof(vertex),
                                                  m_data[0].p.m_x));
      m_vao->setVertexAttributePointer(0,3,GL_FLOAT,sizeof(vertex),0);
      m_vao->setVertexAttributePointer(2,3,GL_FLOAT,sizeof(vertex),3);
      m_vao->setNumIndices(m_data.size());
      m_vao->draw();
      m_vao->unbind();
      //end 0116
    }
  m_axis->draw(m_mouseGlobalTX);

}
//by yao 0118

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::mouseMoveEvent( QMouseEvent* _event )
{
  // note the method buttons() is the button state when event was called
  // that is different from button() which is used to check which button was
  // pressed when the mousePress/Release event is generated
  if ( m_win.rotate && _event->buttons() == Qt::LeftButton )
  {
    int diffx = _event->x() - m_win.origX;
    int diffy = _event->y() - m_win.origY;
    m_win.spinXFace += static_cast<int>( 0.5f * diffy );
    m_win.spinYFace += static_cast<int>( 0.5f * diffx );
    m_win.origX = _event->x();
    m_win.origY = _event->y();
    update();
  }
  // right mouse translate code
  else if ( m_win.translate && _event->buttons() == Qt::RightButton )
  {
    int diffX      = static_cast<int>( _event->x() - m_win.origXPos );
    int diffY      = static_cast<int>( _event->y() - m_win.origYPos );
    m_win.origXPos = _event->x();
    m_win.origYPos = _event->y();
    //std::cout<<"x1: "<<_event->x()<<"y1: "<<_event->y();
    m_modelPos.m_x += INCREMENT * diffX;
    m_modelPos.m_y -= INCREMENT * diffY;
    update();
  }
}


//----------------------------------------------------------------------------------------------------------------------
void NGLScene::mousePressEvent( QMouseEvent* _event )
{
  // that method is called when the mouse button is pressed in this case we
  // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
  if ( _event->button() == Qt::LeftButton )
  {
    m_win.origX  = _event->x();
    m_win.origY  = _event->y();
    m_win.rotate = true;
    update();
    //end 0121


    // update();
  }
  // right mouse translate mode
  else if ( _event->button() == Qt::RightButton )
  {
    m_win.origXPos  = _event->x();
    m_win.origYPos  = _event->y();
    m_win.translate = true;
  }
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::mouseReleaseEvent( QMouseEvent* _event )
{
  // that event is called when the mouse button is released
  // we then set Rotate to false
  if ( _event->button() == Qt::LeftButton )
  {
    m_win.rotate = false;
  }
  // right mouse translate mode
  if ( _event->button()
       == Qt::RightButton )
  {
    m_win.translate = false;
  }
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::wheelEvent( QWheelEvent* _event )
{

  // check the diff of the wheel position (0 means no change)
  if ( _event->delta() > 0 )
  {
    m_modelPos.m_z += ZOOM;
  }
  else if ( _event->delta() < 0 )
  {
    m_modelPos.m_z -= ZOOM;
  }
  update();
}
//----------------------------------------------------------------------------------------------------------------------
void NGLScene::vboChanged( int _index  )
{
  m_drawIndex=_index;
  update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::toggleNormals(bool _value )
{
  m_drawNormals=_value;
  update();
}

void NGLScene::showSkeletons(bool _value )
{
  m_drawSkeletons=_value;
  update();
}

void NGLScene::resetanimation(bool _value )
{
  m_resetanimation=_value;
  update();
}
void NGLScene::elimination(bool _value)
{
    m_elimination=_value;
    update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setNormalSize(int _value)
{
  m_normalSize=_value;
  update();
}
//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setScale(float _x, float _y,float _z )
{
  m_scale.scale(_x,_y,_z);
  update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setTranslate(float _x, float _y, float _z )
{

  m_translate.translate(_x,_y,_z);
  update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setRotate(float _x,  float _y, float _z  )
{
  ngl::Mat4 rx=1.0f;
  ngl::Mat4 ry=1.0f;
  ngl::Mat4 rz=1.0f;
  rx.rotateX(_x);
  ry.rotateY(_y);
  rz.rotateZ(_z);
  m_rotate=rz*ry*rx;
  // now for the incorrect gimbal 1
  m_gimbal.identity();
  m_gimbal.rotateX(_x);
  m_gimbal.rotateY(_y);
  m_gimbal.rotateZ(_z);

  update();
}
//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setPace(float _x,  float _y, float _z  )
{

  m_sketeon_pace1=_x;
  m_sketeon_pace2=_y;
  m_sketeon_pace3=_z;
  update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setColour( float _r,   float _g,  float _b  )
{
  m_colour.set(_r,_g,_b);
  m_material.setDiffuse(m_colour);
  m_material.loadToShader("material");
  update();
}


//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setMatrixOrder(int _index  )
{
  switch(_index)
  {
    case 0 : { m_matrixOrder=NGLScene::MatrixOrder::RTS;   break; }
    case 1 : { m_matrixOrder=NGLScene::MatrixOrder::TRS;   break; }
    case 2 : { m_matrixOrder=NGLScene::MatrixOrder::GIMBALLOCK; break; }
    case 3 : { m_matrixOrder=NGLScene::MatrixOrder::EULERTS; break; }
    case 4 : { m_matrixOrder=NGLScene::MatrixOrder::TEULERS; break; }
    default : break;
  }
update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::setEuler(float _angle, float _x,  float _y,  float _z )
{
  m_euler=1.0f;
  m_euler.euler(_angle,_x,_y,_z);
  update();
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::resetMouse()
{
  m_win.spinXFace=0;
  m_win.spinYFace=0;
  m_win.origX=0;
  m_win.origY=0;
  update();
}
//----------------------------------------------------------------------------------------------------------------------


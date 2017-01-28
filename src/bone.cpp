#include"bone.h"
#include<ngl/Vec3.h>
#include<ngl/Obj.h>
#include <string>
#include <sstream>
#include <iostream>
#include<math.h>
#include"Quaternion.h"
#include<ngl/Mat4.h>
void Bone::initializeBone(std::vector<ngl::Vec3> _verts,const std::string &_fname)
 {
     loadBone(_fname);
     m_jointNumber=m_chain.size();
     m_boneNumber=m_chain.size()-1;
     m_vertNumber=_verts.size();

     m_bindLabel.reset(new size_t [m_vertNumber*m_boneNumber]);
     m_hierarchyLabel.reset(new float [m_boneNumber]);
     //initialize the bone inherent relationship
     m_hierarchyLabel[0]=1;
     for(size_t i=1;i<m_boneNumber;++i)
     {
         m_hierarchyLabel[i]=m_hierarchyLabel[i-1]/2;
     }
     m_biharmonicWeights.reset(new float [m_vertNumber*m_boneNumber]);

     initializeBiharmonicWeights();
     m_JointLabel.reset(new size_t [m_vertNumber*m_jointNumber]);
     m_vertBoneDistance.reset(new float [m_vertNumber*m_boneNumber]);
     judgeJointZone(_verts);
 }

 ngl::Vec3 Bone::buildBoneAxis(ngl::Vec3 _chainStart,ngl::Vec3 _chainEnd)
 {
    ngl::Vec3 axis;
    axis.m_x=(_chainStart.m_x+_chainEnd.m_x)/2;
    axis.m_y=(_chainStart.m_x+_chainEnd.m_y)/2;
    axis.m_z=(_chainStart.m_x+_chainEnd.m_z)/2;
    return axis;
 }

 /*void Bone::bindControl(std::vector<ngl::Vec3> _verts,std::vector<ngl::Vec3> _bones)
 {

     for(size_t i=0;i<m_boneNumber;++i)
     {
         for(size_t j=0;j<m_vertNumber;++j)
         {
            float distance=sqrt((_verts[j].m_x-_bones[i].m_x)*(_verts[j].m_x-_bones[i].m_x)
                                +(_verts[j].m_y-_bones[i].m_y)*(_verts[j].m_y-_bones[i].m_y)
                                +(_verts[j].m_z-_bones[i].m_z)*(_verts[j].m_z-_bones[i].m_z));
            if(distance<=threshold)
                m_bindLabel[i+j*m_boneNumber]=1;
           }
     }

 }

const size_t* Bone::getBindLabel()
{
          return m_bindLabel.get();
}*/


std::vector<ngl::Vec3> Bone::ApplyDeformation(std::vector<ngl::Vec3> _verts, std::vector<float> _roatationAngle, bool _elimination)
{
  std::vector <ngl::Vec3> m_new_vertex;

  for(size_t i=0;i<m_vertNumber;++i)
  {   ngl::Vec3 vert;
      ngl::Mat4 bindBoneCoordinate;
      ngl::Mat4 worldCoordinate;
      size_t bindBoneNumber=0;
      bool bindMark=false;
      m_chainForAnimation=m_chain;
    for(size_t j=0;j<m_boneNumber;++j)
    {
        float theta=_roatationAngle[j];
        ngl::Vec3 v;
        v.m_x=_verts[i].m_x;
        v.m_y=_verts[i].m_y;
        v.m_z=_verts[i].m_z;
        v=bonecoordinateConvertor(v,m_boneCoordinates[j]);
        //create the roatation axis in bone coordinates
        ngl::Vec3 axis_point_world(m_chainForAnimation[j].m_x,m_chainForAnimation[j].m_y+1,m_chainForAnimation[j].m_z);
        ngl::Mat4 boneCoordinates_ForAnimation=boneCoordinatesMatrix(m_chainForAnimation[j],m_chainForAnimation[j+1]);
        ngl::Vec3 axis_point_local=bonecoordinateConvertor(axis_point_world,boneCoordinates_ForAnimation);
        ngl::Vec3 axis=ngl::Vec3(axis_point_local.m_x,axis_point_local.m_y,axis_point_local.m_z);

        //quaternion and its inversion for DQS
        Quaternion q(cos(theta*M_PI/360),sin(theta*M_PI/360)*axis.m_x,sin(theta*M_PI/360)*axis.m_y,sin(theta*M_PI/360)*axis.m_z);
        Quaternion q1(cos(theta*M_PI/360),-sin(theta*M_PI/360)*axis.m_x,-sin(theta*M_PI/360)*axis.m_y,-sin(theta*M_PI/360)*axis.m_z);
        //Dual Quaternion Skinning: v_new=Q*v*Q_1
        Quaternion v_local(v);
        v_local=v_local.QuaternionDot(q,v_local);
        v_local=v_local.QuaternionDot(v_local,q1);
        v.m_x=v_local.m_x;v.m_y=v_local.m_y;v.m_z=v_local.m_z;

        ngl::Mat4 worldCoordinate_ForAnimation=worldCoordinateMatrix(m_chainForAnimation[j],m_chainForAnimation[j+1]);
        ngl::Vec3 vert_world=worldcoordinateConvertor(v,worldCoordinate_ForAnimation);

        //if(m_biharmonicWeights[i*m_boneNumber]>0.5)
        vert.m_x+=vert_world.m_x*m_biharmonicWeights[i*m_boneNumber+j];//*m_bindLabel[i*m_boneNumber+j];
        vert.m_y+=vert_world.m_y*m_biharmonicWeights[i*m_boneNumber+j];//*m_bindLabel[i*m_boneNumber+j];
        vert.m_z+=vert_world.m_z*m_biharmonicWeights[i*m_boneNumber+j];//*m_bindLabel[i*m_boneNumber+j];
        //rotate the bone after vertex rotation
        for(size_t p=j+1;p<m_chain.size();++p)
        {
        ngl::Vec3 axis_endpoint_local=bonecoordinateConvertor(m_chainForAnimation[p],boneCoordinates_ForAnimation);
        Quaternion axis_local(axis_endpoint_local);
        axis_local=v_local.QuaternionDot(q,axis_local);
        axis_local=v_local.QuaternionDot(axis_local,q1);
        axis_endpoint_local.m_x=axis_local.m_x;axis_endpoint_local.m_y=axis_local.m_y;axis_endpoint_local.m_z=axis_local.m_z;
        m_chainForAnimation[p]=worldcoordinateConvertor(axis_endpoint_local,worldCoordinate_ForAnimation);
        }
        //eliminate bulges
        if(m_bindLabel[i*m_boneNumber+j]==1)
        {
           bindBoneCoordinate=boneCoordinatesMatrix(m_chainForAnimation[j],m_chainForAnimation[j+1]);
           worldCoordinate=worldCoordinateMatrix(m_chainForAnimation[j],m_chainForAnimation[j+1]);
           bindBoneNumber=j;
            bindMark=true;
        }
     }
    if(bindMark&&_elimination)
    {
        vert=bulgeElimination(vert,bindBoneCoordinate,worldCoordinate,i,bindBoneNumber);
    }
    //put the deformed vertices back to the vertices vector in obj
    m_new_vertex.push_back(vert);
 }

  return m_new_vertex;
}



bool Bone::loadBone(const std::string &_fname)
{
    std::ifstream in(_fname.c_str());
    if (in.is_open() != true)
    {
    std::cout<<"Bone NOT FOUND !!!! "<<_fname.c_str()<<"\n";
    return false;
     }
    std::string str;
    ngl::Vec3 vert;
    std::vector<ngl::Vec3> m_chain_test;
    while(std::getline(in,str))
    {
        std::istringstream iss(str.c_str());
        iss>>vert.m_x>>vert.m_y>>vert.m_z;
        //vert.m_x=str[0];vert.m_y=str[1];vert.m_z=str[2];
        m_chain_test.push_back(vert);
    }
    for(size_t i=1;i<(m_chain_test.size());++i)
    {
        m_chain.push_back(m_chain_test[i]);
    }

}
void Bone::initializeBiharmonicWeights()
{      const std::string fname="weights.txt";
    std::ifstream in(fname.c_str());
    if (in.is_open() != true)
    {
    std::cout<<"Weights NOT FOUND !!!! "<<fname.c_str()<<"\n";
     }
    std::string str;
    size_t index=0;
    float w1;
    float w2;
    float w3;
    while(std::getline(in,str))
    {
        std::istringstream iss(str.c_str());
        iss>>w1>>w2>>w3;
        m_biharmonicWeights[index*m_boneNumber]=w3;
        m_biharmonicWeights[index*m_boneNumber+1]=w2;
        m_biharmonicWeights[index*m_boneNumber+2]=w1;
        index++;
    }

/*
    for(size_t i=0;i<(m_vertNumber);++i)
    {
        if((m_biharmonicWeights[i*m_boneNumber]+m_biharmonicWeights[i*m_boneNumber+1]+m_biharmonicWeights[i*m_boneNumber+2])<0.5)
           // std::cout<<"Vertex"<<i<<std::endl;
    }*/

/*
 for(size_t i=0;i<(m_vertNumber*m_boneNumber);++i)
    {
        m_biharmonicWeights[i]=0.33333f;

    }*/
}

void Bone::judgeJointZone(std::vector<ngl::Vec3> _verts)
{   float distance;
    for(size_t i=0;i<m_boneNumber;++i)
    {   ngl::Mat4 boneCoordinate=boneCoordinatesMatrix(m_chain[i],m_chain[i+1]);
        m_boneCoordinates.push_back(boneCoordinate);
    }
    for(size_t i=0;i<m_boneNumber;++i)
    {   ngl::Mat4 worldCoordinate=worldCoordinateMatrix(m_chain[i],m_chain[i+1]);
        m_worldCoordinates.push_back(worldCoordinate);
    }

    for(size_t i=0;i<m_vertNumber;++i)
    {
        for(size_t j=0;j<m_boneNumber;++j)
        {
            //judge whether _verts[i] is belong to m_boneCoordinate[i]
            ngl::Vec3 v;
            v.m_x = m_boneCoordinates[j].m_00*_verts[i].m_x + m_boneCoordinates[j].m_10*_verts[i].m_y+m_boneCoordinates[j].m_20*_verts[i].m_z+m_boneCoordinates[j].m_30;
            v.m_y = m_boneCoordinates[j].m_01*_verts[i].m_x + m_boneCoordinates[j].m_11*_verts[i].m_y+m_boneCoordinates[j].m_21*_verts[i].m_z+m_boneCoordinates[j].m_31;
            v.m_z = m_boneCoordinates[j].m_02*_verts[i].m_x + m_boneCoordinates[j].m_12*_verts[i].m_y+m_boneCoordinates[j].m_22*_verts[i].m_z+m_boneCoordinates[j].m_32;
            float boneLenght=sqrt((m_chain[j].m_x-m_chain[j+1].m_x)*(m_chain[j].m_x-m_chain[j+1].m_x)+
                                   (m_chain[j].m_y-m_chain[j+1].m_y)*(m_chain[j].m_y-m_chain[j+1].m_y)+
                                   (m_chain[j].m_z-m_chain[j+1].m_z)*(m_chain[j].m_z-m_chain[j+1].m_z));
            distance=sqrt(v.m_x*v.m_x+v.m_z*v.m_z);
            if((v.m_x>0.8*boneLenght)&&(m_biharmonicWeights[i*m_boneNumber+j]>0.5)&&(j!=(m_boneNumber-1)))
            {
             if(j==0)
            m_bindLabel[i*m_boneNumber+j]=1;
            else if((j==1)&&(m_bindLabel[i*m_boneNumber]==0))
            {
                m_bindLabel[i*m_boneNumber+j]=1;
            }
            else if((j==2)&&(m_bindLabel[i*m_boneNumber]==0)&&(m_bindLabel[i*m_boneNumber+1]==0))
            {
                m_bindLabel[i*m_boneNumber+j]=1;
            }

            m_vertBoneDistance[i*m_boneNumber+j]=distance;
            }
            else
            {
                m_bindLabel[i*m_boneNumber+j]=0;
            }
           // std::cout<<v.m_x<<std::endl;
            //std::cout<<"No "<<i<<"Bone "<<j<<"distance"<<m_vertBoneDistance[i*m_boneNumber+j]<<"BIND "<< m_bindLabel[i*m_boneNumber+j]<<std::endl;
        }
    }

}

ngl::Mat4 Bone::worldCoordinateMatrix(ngl::Vec3 _boneStart,ngl::Vec3 _boneEnd)
{   /*
    ngl::Vec3 X(-_boneStart.m_x+_boneEnd.m_x,-_boneStart.m_y+_boneEnd.m_y,-_boneStart.m_z+_boneEnd.m_z);
    ngl::Vec3 Y(0,1,-X.m_y/X.m_z);
    ngl::Vec3 Z=caculate(X,Y);
    ngl::Mat4 Ai(X.m_x,X.m_y,X.m_z,0,
                Y.m_x,Y.m_y,Y.m_z,0,
                Z.m_x,Z.m_y,Z.m_z,0,
                _boneStart.m_x,_boneStart.m_y,_boneStart.m_z,1
                );
                */
    ngl::Vec3 X(-_boneStart.m_x+_boneEnd.m_x,-_boneStart.m_y+_boneEnd.m_y,-_boneStart.m_z+_boneEnd.m_z);
    ngl::Vec3 Y(0,1,-X.m_y/X.m_z);
    ngl::Vec3 Z=caculate(X,Y);
    ngl::Mat4 Ai(X.m_x,X.m_y,X.m_z,0,
                Y.m_x,Y.m_y,Y.m_z,0,
                Z.m_x,Z.m_y,Z.m_z,0,
                _boneStart.m_x,_boneStart.m_y,_boneStart.m_z,1
                );
    return Ai;
}
ngl::Mat4 Bone::boneCoordinatesMatrix(ngl::Vec3 _boneStart,ngl::Vec3 _boneEnd)
{
    ngl::Mat4 Ai=worldCoordinateMatrix(_boneStart,_boneEnd);
    ngl::Mat4 Ai_1=Ai.inverse();
    return Ai_1;
}

ngl::Vec3 Bone::caculate(ngl::Vec3 a,ngl::Vec3 b)
{
 ngl::Vec3 c;
 c.m_x = a.m_y*b.m_z-a.m_z*b.m_y;
 c.m_y = a.m_z*b.m_x-a.m_x*b.m_z;
 c.m_z = a.m_x*b.m_y-a.m_y*b.m_x;
 return c;
}
//after the rotation, detect the distance between every vertex and bone again
//if this distance is different from the original distance, let we reproject it.
ngl::Vec3 Bone::bulgeElimination(ngl::Vec3 _verts,ngl::Mat4 _bindBoneCoordinate,ngl::Mat4 _worldCoordinate,size_t _i,size_t _boneNumber)
{
    std::cout<<"Enter the bULGE E......"<<std::endl;
    double distance=0;
    double projection_factor=0;
     //fisrt convert vert position from world coordinate to bone coordinate
       ngl::Vec3 _verts_local=bonecoordinateConvertor(_verts,_bindBoneCoordinate);
       distance=sqrt(_verts_local.m_x*_verts_local.m_x+_verts_local.m_z*_verts_local.m_z);
       projection_factor=distance/m_vertBoneDistance[_i*m_boneNumber+_boneNumber];
       //judge whether bulge happens
       if(projection_factor>=1)
       {
            _verts_local.m_x/=projection_factor;
           _verts_local.m_z/=projection_factor;

        }
       //convert vert from local coordinate back to world coordinate
       ngl::Vec3 _verts_world=worldcoordinateConvertor(_verts_local,_worldCoordinate);
       return _verts_world;
 }


ngl::Vec3 Bone::worldcoordinateConvertor(ngl::Vec3 _v,ngl::Mat4 _worldCoordinate)
{   ngl::Vec3 vert;
    vert.m_x = _worldCoordinate.m_00*_v.m_x + _worldCoordinate.m_10*_v.m_y+_worldCoordinate.m_20*_v.m_z+_worldCoordinate.m_30;
    vert.m_y = _worldCoordinate.m_01*_v.m_x + _worldCoordinate.m_11*_v.m_y+_worldCoordinate.m_21*_v.m_z+_worldCoordinate.m_31;
    vert.m_z = _worldCoordinate.m_02*_v.m_x + _worldCoordinate.m_12*_v.m_y+_worldCoordinate.m_22*_v.m_z+_worldCoordinate.m_32;
    return vert;
}
ngl::Vec3 Bone::bonecoordinateConvertor(ngl::Vec3 _v,ngl::Mat4 _boneCoordinate)
{   ngl::Vec3 vert;
    vert.m_x = _boneCoordinate.m_00*_v.m_x + _boneCoordinate.m_10*_v.m_y+_boneCoordinate.m_20*_v.m_z+_boneCoordinate.m_30;
    vert.m_y = _boneCoordinate.m_01*_v.m_x + _boneCoordinate.m_11*_v.m_y+_boneCoordinate.m_21*_v.m_z+_boneCoordinate.m_31;
    vert.m_z = _boneCoordinate.m_02*_v.m_x + _boneCoordinate.m_12*_v.m_y+_boneCoordinate.m_22*_v.m_z+_boneCoordinate.m_32;
    return vert;
}

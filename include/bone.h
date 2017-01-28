#ifndef BONE_H
#define BONE_H
#include <ngl/Vec3.h>
#include <memory>
#include <vector>
#include<ngl/Mat4.h>
class Bone
{
public:
    Bone()
    {
    m_boneNumber=0;
    m_vertNumber=0;
    }
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief initialize all parameters and save the distance between vertex and its bone
    /// called from NGLScene
    /// @param[in] _index the value of all obj verts
    //----------------------------------------------------------------------------------------------------------------------
    void initializeBone(std::vector<ngl::Vec3> _verts,const std::string &_fname);
    std::vector <ngl::Vec3> m_chain;
    std::vector <ngl::Vec3> m_chainForAnimation;
    void test();
    ngl::Vec3 buildBoneAxis(ngl::Vec3 _chainStart,ngl::Vec3 _chainEnd);
    //bind vertices to bones
     //void bindControl(std::vector<ngl::Vec3> _verts,std::vector<ngl::Vec3> _bones);
    // const size_t* getBindLabel();
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief load bones from outside file
     /// called from NGLScene
     /// @param[in] _index the name of file
     //----------------------------------------------------------------------------------------------------------------------
     bool loadBone(const std::string &_fname);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief apply deformation to vertices
     /// called from NGLScene
     /// @param[in] _index the value of all vertices
     //----------------------------------------------------------------------------------------------------------------------
     std::vector<ngl::Vec3> ApplyDeformation(std::vector<ngl::Vec3> _verts, std::vector<float> _roatationAngle,bool _elimination);
     void initializeBiharmonicWeights();
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief judge the which bone zone the vert is , save the label in m_JointLabel and the distance in m_vertBoneDistance
     /// called from initializeBone();
     /// @param[in] _index the value of all vertices
     //----------------------------------------------------------------------------------------------------------------------
     void judgeJointZone(std::vector<ngl::Vec3> _verts);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief use bone's two joints as x asix in local coordinate and build the local bone coordinate
     /// called from initializeBone();
     /// @param[in] _boneStart the start point of one bone ,_boneEnd the end point of this bone
     /// @param[out] return the inversed mat including the bone coordinate's position and direction
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Mat4 boneCoordinatesMatrix(ngl::Vec3 _boneStart,ngl::Vec3 _boneEnd);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief calculate the normal of two vectors
     /// called from boneCoordinatesConversion();
     /// @param[in] _a and _b are the two vectors
     /// @param[out] return normal of _a and _b
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Vec3 caculate(ngl::Vec3 a,ngl::Vec3 b);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief detect vertex bulges and eliminate them by reprojection
     /// called NGLScene;
     /// @param[in] _verts the values of vertex after deformation
     /// @param[out] _verts the values of vertex after reprojection
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Vec3 bulgeElimination(ngl::Vec3 _verts_local, ngl::Mat4 _bindBoneCoordinate, ngl::Mat4 _worldCoordinate, size_t _i, size_t _boneNumber);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief convert vertex position in local bone coordinate to world coordinate
     /// called bulgeElimination;
     /// @param[in] _v the values of vertex in local bone coordinate,_worldCoordinate the mat4 including world coordinate position
     ///            and direction
     /// @param[out] _verts the values of vertex in world coordinate
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Vec3 worldcoordinateConvertor(ngl::Vec3 _v,ngl::Mat4 _worldCoordinate);
     ngl::Vec3 bonecoordinateConvertor(ngl::Vec3 _v,ngl::Mat4 _boneCoordinate);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief convert bone coordinate to world coordinate
     /// called bulgeElimination;
     /// @param[in] _boneStart the start point of x asix in bone coordinate,_boneEnd the end point of x asix in bone coordinate
     /// @param[out] mat4 including world coordinate position
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Mat4 worldCoordinateMatrix(ngl::Vec3 _boneStart,ngl::Vec3 _boneEnd);

private:
    //float threshold=0.5;
    std::unique_ptr<size_t []> m_bindLabel;
    size_t m_boneNumber;//=_bones.size();
    size_t m_jointNumber;
    size_t m_vertNumber;//=_verts.size();
    std::unique_ptr<float []> m_hierarchyLabel;
    std::unique_ptr<float []> m_biharmonicWeights;
    std::unique_ptr<size_t []> m_JointLabel;
    std::unique_ptr<float []> m_vertBoneDistance;
    std::vector<ngl::Mat4> m_boneCoordinates;
    std::vector<ngl::Mat4> m_worldCoordinates;



};


#endif // BONE_H

#include"Quaternion.h"
Quaternion::Quaternion(ngl::Vec3 _vert)
{
    m_w=0;
    m_x=_vert.m_x;
    m_y=_vert.m_y;
    m_z=_vert.m_z;
}
Quaternion::Quaternion(float _w,float _x,float _y,float _z)
{
    m_w=_w;
    m_x=_x;
    m_y=_y;
    m_z=_z;
}
Quaternion Quaternion::QuaternionDot(Quaternion _lq,Quaternion _rq)
{
    float w=_lq.m_w*_rq.m_w-_lq.m_y*_rq.m_y-_lq.m_z*_rq.m_z-_lq.m_x*_rq.m_x;
    float x=_lq.m_x*_rq.m_w+_lq.m_w*_rq.m_x+_lq.m_y*_rq.m_z-_lq.m_z*_rq.m_y;
    float y=_lq.m_z*_rq.m_x-_lq.m_x*_rq.m_z+_lq.m_w*_rq.m_y+_lq.m_y*_rq.m_w;
    float z=_lq.m_x*_rq.m_y-_lq.m_y*_rq.m_x+_lq.m_w*_rq.m_z+_lq.m_z*_rq.m_w;
    return Quaternion(w,x,y,z);
}

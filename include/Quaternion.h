#ifndef DUALQUATERNIONSKINNINGMETHOD_H
#define DUALQUATERNIONSKINNINGMETHOD_H

#include<ngl/Vec4.h>
class Quaternion
{
public:
    struct
    {     float m_w;
          float m_x;
          float m_y;
          float m_z;

     };
    Quaternion(ngl::Vec3 _vert);
    Quaternion(float _w,float _x,float _y,float _z);
    Quaternion QuaternionDot(Quaternion _lq,Quaternion _rq);

private:

};


#endif // DUALQUATERNIONSKINNINGMETHOD_H

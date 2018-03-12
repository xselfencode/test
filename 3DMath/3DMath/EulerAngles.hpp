//
//  EulerAngles.hpp
//  3DMath
//
//  Created by 宁真 on 2017/11/25.
//  Copyright © 2017年 ningzhen. All rights reserved.
//

#ifndef EulerAngles_hpp
#define EulerAngles_hpp

#include <stdio.h>

#endif /* EulerAngles_hpp */


class Quaternion;
class Matrix4x3;
class RotationMatrix;
class EularAngles {
public:
    float heading;
    float pitch;
    float bank;
    
    EularAngles(){}
    
    EularAngles(float h, float p, float b) :
    heading(h),pitch(p),bank(b){}
    
    void identity() {pitch = bank = heading = 0.0f;}
    
    void canonize();
    
    void fromObjectToInertialQuaternion(const Quaternion &q);
    void fromInertialToObjectQuaternion(const Quaternion &q);
    
    void fromObjectToWorldMatrix(const Matrix4x3 &m);
    void fromWorldToObjectMatrix(const Matrix4x3 &m);
    
    void fromRotationMatrix(const RotationMatrix &m);
};

extern const EularAngles kEularAnglesIdentity;

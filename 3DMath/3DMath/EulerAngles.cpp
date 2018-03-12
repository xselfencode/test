//
//  EulerAngles.cpp
//  3DMath
//
//  Created by 宁真 on 2017/11/25.
//  Copyright © 2017年 ningzhen. All rights reserved.
//

#include "EulerAngles.hpp"
#include <math.h>
#include "MathUtil.h"
#include "Quaternion.hpp"
#include "Matrix4x3.hpp"

const EularAngles kEulerAngelsIdentity(0.0f,0.0f,0.0f);

void EularAngles::canonize() {
    pitch = wrapPi(pitch);
    if (pitch < -kPiOver2) {
        pitch = -kPi - pitch;
        heading += kPi;
        bank += kPi;
    }else if (pitch > kPiOver2) {
        pitch = kPi - pitch;
        heading += kPi;
        bank += kPi;
    }
    
    if (fabs(pitch) > kPiOver2 -1e-4) {
        heading += bank;
        bank = 0.0f;
    }else {
        bank = wrapPi(bank);
    }
    
    heading = wrapPi(heading);
    
}

void EularAngles::fromObjectToInertialQuaternion(const Quaternion &q) {
    float sp = -2.0f * (q.y * q.z - q.w * q.x);
    
    if (fabs(sp) > 0.9999f) {
        pitch = kPiOver2 * sp;
        heading = atan2(-q.x * q.z + q.y * q.w ,0.5f - q.y * q.y - q.z * q.z);
        bank = 0.0f;
        
    }
}

void EularAngles:: fromObjectToWorldMatrix(const Matrix4x3 &m) {
    float sp = -m.m32;
}

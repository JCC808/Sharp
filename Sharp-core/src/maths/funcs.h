//
// Created by caudij on 7/23/2018.
//

#pragma once

#include <cmath>

namespace Sharp {namespace maths {

    inline float toRadians(float degrees){
        return degrees* ((float)M_PI/180.0f);
    }

    inline float toDegrees(float radians){
        return radians* (180.0f/(float)M_PI);
    }

}}
//
// Created by caudij on 7/23/2018.
//

#include "mat4.h"


namespace Sharp {namespace maths {

    mat4::mat4(){
        for (float &i : element) {
            i = 0.0f;
        }
    }
    mat4::mat4(float diagonal){
        for (float &i : element) {
            i = 0.0f;
        }

        element[0+0*4] = diagonal;
        element[1+1*4] = diagonal;
        element[2+2*4] = diagonal;
        element[3+3*4] = diagonal;

    }

    mat4 mat4::identity(){
        mat4 result(1.0f);
        return result;
    }

    mat4& mat4::multiply(const mat4& other){
        for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++){
                float sum = 0.0f;
                for(int e = 0; e < 4; e++){
                    sum += element[x+e*4]*other.element[e+y*4];
                }
                element[x+y*4] = sum;
            }
        }
        return *this;
    }
    mat4 operator*(mat4 left, const mat4& right){
        return left.multiply(right);
    }
    void mat4::operator*=(const mat4& right){
        multiply(right);
    }

    mat4 mat4::orthographic(float& left, float& right, float& top, float& bottom, float& near, float& far){
        mat4 result(1.0f);

        float a = right - left;
        float b = top - bottom;
        float c = far - near;

        result.element[0+0*4] = 2/a;
        result.element[1+1*4] = 2/b;
        result.element[2+2*4] = -2/c;
        result.element[0+3*4] = -(right+left)/a;
        result.element[1+3*4] = -(top+bottom)/b;
        result.element[2+3*4] = -(far+near)/c;

        return result;
    }
    mat4 mat4::perspective(float& fov, float& aspectRatio, float& near, float& far){
        mat4 result;

        float b = 1.0f / (float) tan((double)toRadians(fov / 2.0f));
        float a = b/aspectRatio;
        float c = -(far+near)/(far-near);
        float d = -(2*far*near)/(far-near);

        result.element[0+0*4] = a;
        result.element[1+1*4] = b;
        result.element[2+2*4] = c;
        result.element[3+2*4] = -1.0f;
        result.element[2+3*4] = d;

        return result;
    }

    mat4 mat4::translation(const vec3& translation){
        mat4 result(1.0f);

        result.element[0+3*4] = translation.m_x;
        result.element[1+3*4] = translation.m_y;
        result.element[2+3*4] = translation.m_z;

        return result;
    }
    mat4 mat4::rotation(float& angle, const vec3& axis){
        mat4 result(1.0f);

        auto c = (float)cos((double)toRadians(angle));
        auto s = (float)sin((double)toRadians(angle));

        float x = axis.m_x;
        float y = axis.m_y;
        float z = axis.m_z;

        result.element[0+0*4] = x*x*(1.0f - c)+c;
        result.element[0+1*4] = y*x*(1.0f-c)+z*s;
        result.element[0+2*4] = x*z*(1.0f-c)-y*s;

        result.element[0+1*4] = x*y*(1.0f-c)-z*s;
        result.element[1+1*4] = y*y*(1.0f-c)+c;
        result.element[2+1*4] = y*z*(1.0f-c)+x*s;

        result.element[0+2*4] = x*z*(1.0f-c)+y*s;
        result.element[1+2*4] = y*z*(1.0f-c)-x*s;
        result.element[2+2*4] = z*z*(1.0f-c)+c;

        return result;
    }
    mat4 mat4::scale(const vec3& scale){
        mat4 result(1.0f);

        result.element[0+3*4] = scale.m_x;
        result.element[1+3*4] = scale.m_y;
        result.element[2+3*4] = scale.m_z;

        return result;
    }
}}
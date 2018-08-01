//
// Created by caudij on 7/22/2018.
//

#include "vec4.h"
#include <iostream>

namespace Sharp {namespace maths {

        vec4::vec4() {
            m_x = 0.0f;
            m_y = 0.0f;
            m_z = 0.0f;
            m_t = 0.0f;
        }

        vec4::vec4(const float& x, const float& y, const float& z, const float& t) {
            m_x = x;
            m_y = y;
            m_z = z;
            m_t = t;
        }

        vec4 vec4::add(const vec4 &other) {
            m_x += other.m_x;
            m_y += other.m_y;
            m_z += other.m_z;
            m_t += other.m_t;

            return *this;
        }
        vec4 vec4::subtract(const vec4& other){
            m_x -= other.m_x;
            m_y -= other.m_y;
            m_z -= other.m_z;
            m_t -= other.m_t;

            return *this;
        }
        vec4 vec4::multiply(const vec4& other){
            m_x *= other.m_x;
            m_y *= other.m_y;
            m_z *= other.m_z;
            m_t *= other.m_t;

            return *this;
        }
        vec4 vec4::divide(const vec4& other){
            m_x /= other.m_x;
            m_y /= other.m_y;
            m_z /= other.m_z;
            m_t /= other.m_t;


            return *this;
        }

        void vec4::print(){
            std::cout<< "vector: (" << m_x << ", " << m_y << ", " << m_z << ", " << m_t << ")" <<std::endl;
        }

        vec4 operator+(vec4 left, const vec4& right){
            return left.add(right);
        }
        vec4 operator-(vec4 left, const vec4& right){
            return left.subtract(right);
        }
        vec4 operator*(vec4 left, const vec4& right){
            return  left.multiply(right);
        }
        vec4 operator/(vec4 left, const vec4& right){
            return left.divide(right);
        }

        void vec4::operator+=(const vec4& right){
            add(right);
        }
        void vec4::operator-=(const vec4& right){
            subtract(right);
        }
        void vec4::operator*=(const vec4& right){
            multiply(right);
        }
        void vec4::operator/=(const vec4& right){
            divide(right);
        }

        bool vec4::operator==(const vec4& right){
            return (m_x == right.m_x && m_y == right.m_y && m_z == right.m_z && m_t == right.m_t);
        }
        bool vec4::operator!=(const vec4& right){
            return !(*this== right);
        }


    }}
//
// Created by caudij on 7/22/2018.
//

#include "vec3.h"
#include <iostream>

namespace Sharp {namespace maths {

        vec3::vec3() {
            m_x = 0.0f;
            m_y = 0.0f;
            m_z = 0.0f;
        }

        vec3::vec3(const float& x, const float& y, const float& z)
            :m_x(x), m_y(y), m_z(z)
        {}

        vec3 vec3::add(const vec3 &other) {
            m_x += other.m_x;
            m_y += other.m_y;
            m_z += other.m_z;

            return *this;
        }
        vec3 vec3::subtract(const vec3& other){
            m_x -= other.m_x;
            m_y -= other.m_y;
            m_z -= other.m_z;

            return *this;
        }
        vec3 vec3::multiply(const vec3& other){
            m_x *= other.m_x;
            m_y *= other.m_y;
            m_z *= other.m_z;

            return *this;
        }
        vec3 vec3::divide(const vec3& other){
            m_x /= other.m_x;
            m_y /= other.m_y;
            m_z /= other.m_z;
            return *this;
        }

        void vec3::print(){
            std::cout<< "vector: (" << m_x << ", " << m_y << "," <<m_z<< ")" <<std::endl;
        }

        vec3 operator+(vec3 left, const vec3& right){
            return left.add(right);
        }
        vec3 operator-(vec3 left, const vec3& right){
            return left.subtract(right);
        }
        vec3 operator*(vec3 left, const vec3& right){
            return  left.multiply(right);
        }
        vec3 operator/(vec3 left, const vec3& right){
            return left.divide(right);
        }

        void vec3::operator+=(const vec3& right){
            add(right);
        }
        void vec3::operator-=(const vec3& right){
            subtract(right);
        }
        void vec3::operator*=(const vec3& right){
            multiply(right);
        }
        void vec3::operator/=(const vec3& right){
            divide(right);
        }

        bool vec3::operator==(const vec3& right){
            return (m_x == right.m_x && m_y == right.m_y && m_z == right.m_z);
        }
        bool vec3::operator!=(const vec3& right){
            return !(*this== right);
        }


    }}
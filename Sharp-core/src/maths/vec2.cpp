//
// Created by caudij on 7/21/2018.
//

#include "vec2.h"

namespace Sharp {namespace maths {

        vec2::vec2() {
            m_x = 0.0f;
            m_y = 0.0f;
        }

        vec2::vec2(const float& x, const float& y) {
            m_x = x;
            m_y = y;
        }

        vec2 vec2::add(const vec2 &other) {
            m_x += other.m_x;
            m_y += other.m_y;

            return *this;
        }
        vec2 vec2::subtract(const vec2& other){
            m_x -= other.m_x;
            m_y -= other.m_y;

            return *this;
        }
        vec2 vec2::multiply(const vec2& other){
            m_x *= other.m_x;
            m_y *= other.m_y;

            return *this;
        }
        vec2 vec2::divide(const vec2& other){
            m_x /= other.m_x;
            m_y /= other.m_y;

            return *this;
        }

        void vec2::print(){
            std::cout<< "vector: (" << m_x << ", " << m_y << ")" <<std::endl;
        }

        vec2 operator+(vec2 left, const vec2& right){
            return left.add(right);
        }
        vec2 operator-(vec2 left, const vec2& right){
            return left.subtract(right);
        }
        vec2 operator*(vec2 left, const vec2& right){
            return  left.multiply(right);
        }
        vec2 operator/(vec2 left, const vec2& right){
            return left.divide(right);
        }

        void vec2::operator+=(const vec2& right){
            add(right);
        }
        void vec2::operator-=(const vec2& right){
            subtract(right);
        }
        void vec2::operator*=(const vec2& right){
            multiply(right);
        }
        void vec2::operator/=(const vec2& right){
            divide(right);
        }

        bool vec2::operator==(const vec2& right){
            return (m_x == right.m_x && m_y == right.m_y);
        }
        bool vec2::operator!=(const vec2& right){
            return !(*this== right);
        }


    }}
//
// Created by caudij on 7/21/2018.
//

#pragma once

#include <iostream>

namespace Sharp { namespace maths {

    struct vec2 {
        float m_x, m_y;

        vec2();

        vec2(const float& x, const float& y);

        vec2 add(const vec2& other);
        vec2 subtract(const vec2& other);
        vec2 multiply(const vec2& other);
        vec2 divide(const vec2& other);

        void print();

        friend vec2 operator+(vec2 left, const vec2& right);
        friend vec2 operator-(vec2 left, const vec2& right);
        friend vec2 operator*(vec2 left, const vec2& right);
        friend vec2 operator/(vec2 left, const vec2& right);

        void operator+=(const vec2& right);
        void operator-=(const vec2& right);
        void operator*=(const vec2& right);
        void operator/=(const vec2& right);

        bool operator==(const vec2& right);
        bool operator!=(const vec2& right);
    };
} }
//
// Created by caudij on 7/22/2018.
//

#pragma once

namespace Sharp { namespace maths {

        struct vec4 {
            float m_x, m_y, m_z, m_t;

            vec4();

            vec4(const float& x, const float& y, const float& z, const float& t);

            vec4 add(const vec4& other);
            vec4 subtract(const vec4& other);
            vec4 multiply(const vec4& other);
            vec4 divide(const vec4& other);

            void print();

            friend vec4 operator+(vec4 left, const vec4& right);
            friend vec4 operator-(vec4 left, const vec4& right);
            friend vec4 operator*(vec4 left, const vec4& right);
            friend vec4 operator/(vec4 left, const vec4& right);

            void operator+=(const vec4& right);
            void operator-=(const vec4& right);
            void operator*=(const vec4& right);
            void operator/=(const vec4& right);

            bool operator==(const vec4& right);
            bool operator!=(const vec4& right);
        };
}}
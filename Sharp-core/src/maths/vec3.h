//
// Created by caudij on 7/22/2018.
//

#pragma once

namespace Sharp {namespace maths {

        struct vec3 {
            float m_x, m_y, m_z;

            vec3();

            vec3(const float& x, const float& y, const float& z);

            vec3 add(const vec3& other);
            vec3 subtract(const vec3& other);
            vec3 multiply(const vec3& other);
            vec3 divide(const vec3& other);

            void print();

            friend vec3 operator+(vec3 left, const vec3& right);
            friend vec3 operator-(vec3 left, const vec3& right);
            friend vec3 operator*(vec3 left, const vec3& right);
            friend vec3 operator/(vec3 left, const vec3& right);

            void operator+=(const vec3& right);
            void operator-=(const vec3& right);
            void operator*=(const vec3& right);
            void operator/=(const vec3& right);

            bool operator==(const vec3& right);
            bool operator!=(const vec3& right);
        };
}}

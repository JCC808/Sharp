//
// Created by caudij on 7/23/2018.
//

#pragma once

#include <funcs.h>
#include <vec4.h>
#include <vec3.h>

namespace Sharp { namespace maths {

    struct mat4{
        union {
            float element[4*4];
            vec4 column[4];
        };

        mat4();
        explicit mat4(float diagonal);

        static mat4 identity();

        mat4& multiply(const mat4& other);
        friend mat4 operator*(mat4 left, const mat4& right);
        void operator*=(const mat4& right);

        static mat4 orthographic(float& left, float& right, float& up, float& down, float& near, float& far);
        static mat4 perspective(float& fov, float& aspectRatio, float& near, float& far);

        static mat4 translation(const vec3& translation);
        static mat4 rotation(float& angle, const vec3& axis);
        static mat4 scale(const vec3& scale);

    };
}}

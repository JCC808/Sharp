//
// Created by caudij on 7/24/2018.
//

#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/glfw3.h>

namespace Sharp { namespace graphics {

    class Window
    {
    private:
        const char *m_title;
        int m_width, m_height;
        GLFWwindow *m_window;
        bool m_Closed;
    public:
        Window(const char *name, int width, int height);
        ~Window();
        void clear() const;
        void update();
        bool closed() const;

        inline int getWidth() const { return m_width; }
        inline int getHeight() const { return m_height; }
    private:
        bool init();
    };
}}

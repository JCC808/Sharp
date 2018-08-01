//
// Created by caudij on 7/24/2018.
//

#include "window.h"

namespace Sharp { namespace graphics {

    void windowResize(GLFWwindow *window, int width, int height);

    Window::Window(const char *name, int width, int height) {
        m_title = name;
        m_width = width;
        m_height = height;
        if (!init()) glfwTerminate();
    }

    Window::~Window() { glfwTerminate(); }

    bool Window::init() {

        if(!glfwInit()) {
            std::cout << "failed to init GLFW" << std::endl;
            return false;
        }

        m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

        if (!m_window){
            std::cout << "glfw window failed" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetWindowSizeCallback(m_window, windowResize);

        if (glewInit() != GLEW_OK){
            std::cout << "cant init glew" << std::endl;
            return false;
        }


        std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;
        return true;
    }

    void Window::clear() const { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); } // NOLINT

        void Window::update() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    bool Window::closed() const { return glfwWindowShouldClose(m_window) == 1; }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
    void windowResize(GLFWwindow *window, int width, int height) { glViewport(0, 0, width, height); }
#pragma clang diagnostic pop

}}

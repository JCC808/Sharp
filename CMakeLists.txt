cmake_minimum_required(VERSION 3.10)
project(Sharp)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)


set(GLFW_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include)
set(GLFW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/lib-vc2015/glfw3.lib)

set(GLEW_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/include)
set(GLEW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/lib/glew32.lib)


set(SOURCEDIR Sharp-core/src/maths Sharp-core/src/graphics)

set(MATHS
        Sharp-core/src/maths/vec2.cpp
        Sharp-core/src/maths/vec2.h
        Sharp-core/src/maths/maths.h
        Sharp-core/src/maths/vec4.cpp
        Sharp-core/src/maths/vec4.h
        Sharp-core/src/maths/vec3.cpp
        Sharp-core/src/maths/vec3.h
        Sharp-core/src/maths/mat4.cpp
        Sharp-core/src/maths/mat4.h
        Sharp-core/src/maths/funcs.h
)

set(GRAPHICS
        Sharp-core/src/graphics/window.cpp
        Sharp-core/src/graphics/window.h
)

include_directories(
        ${SOURCEDIR}
        ${GLFW_INCLUDE_PATH}
        ${GLEW_INCLUDE_PATH}
)

add_executable(Sharp-core
        ${CMAKE_CURRENT_SOURCE_DIR}/Sharp-core/main.cpp
        ${GRAPHICS}
        ${MATHS}
)

target_link_libraries(Sharp-core
        ${OPENGL_LIBRARY}
        ${GLFW_LIBRARY}
        ${GLEW_LIBRARY}
)

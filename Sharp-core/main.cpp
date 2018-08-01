//
// Created by caudij on 7/22/2018.
//

#include <iostream>
#include "src/maths/maths.h"
#include "src/graphics/window.h"

int main() {
    using namespace Sharp;
    using namespace maths;
    using namespace graphics;

    Window window("Sharp", 960, 540);
    glClearColor(0.2f, 0.5f, 0.2f, 1.0f);

    while (!window.closed()){
        window.clear();

        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);

        window.update();
    }

    vec2 first(2.0,4.0);
    vec2 second(2,2);
    vec2 third;
    third = first / second;
    third.print();
    first.print();
    system("PAUSE");
    return 0;
};
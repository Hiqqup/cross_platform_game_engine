//
// Created by ju on 11/23/25.
//

#pragma once

#include "Window.hpp"

// ReSharper disable once CppUnusedIncludeDirective
#include "../gl_backend.hpp"
#include <GLFW/glfw3.h>

class GlfwWindow : public cpge::Window {
public:
    GlfwWindow();
    ~GlfwWindow() ;
    bool should_close() override;
    void update() override;
private:
    GLFWwindow* window ;
};

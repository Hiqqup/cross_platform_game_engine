//
// Created by ju on 11/19/25.
//

#pragma once
#include "gl_backend.h"
#include <filesystem>
#include <GLFW/glfw3.h>
#include <functional>

class Backend {
public:


    GLFWwindow* window ;
    GLuint shaderProgram;
    GLuint texture;
    GLuint VAO, VBO, EBO;

    virtual void main_loop();

    virtual void initialize_context() ;
    virtual void setup_main_loop_cleanup();
    virtual void do_main_loop(const std::function<void()>& func) = 0;
    virtual std::filesystem::path resolveAssetPath(const std::filesystem::path &relativeAssetPath) = 0 ;

};
extern Backend* global_backend;
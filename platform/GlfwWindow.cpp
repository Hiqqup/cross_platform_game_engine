//
// Created by ju on 11/23/25.
//

#include "GlfwWindow.hpp"
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
}

GlfwWindow::GlfwWindow() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return ;
    }

    // Request an OpenGL ES 3.0 context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);


     window = glfwCreateWindow(1900, 1000, "Cross Platform Game Engine", nullptr, nullptr);
    if (!window ) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return ;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}


GlfwWindow::~GlfwWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool GlfwWindow::should_close() {
    return glfwWindowShouldClose(window);
}

void GlfwWindow::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}
glm::vec2 GlfwWindow::get_window_size() {
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	return glm::vec2(width, height);
}

void GlfwWindow::set_cursor_disabled(bool value) {
    glfwSetInputMode(window, GLFW_CURSOR, value? GLFW_CURSOR_NORMAL:GLFW_CURSOR_DISABLED);
}

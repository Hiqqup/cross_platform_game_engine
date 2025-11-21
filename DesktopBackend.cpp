//
// Created by ju on 11/19/25.
//

#include "DesktopBackend.h"
#include "gl_backend.h"
#include <iostream>

void DesktopBackend::initialize_context() {
    Backend::initialize_context();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
    }
}

std::filesystem::path DesktopBackend::resolveAssetPath(const std::filesystem::path &relativeAssetPath) {
    auto mergedPath = ("./assets" / relativeAssetPath).make_preferred();
    return std::filesystem::canonical(mergedPath);
}


void DesktopBackend::do_main_loop(const std::function<void()>& func) {
    while(!glfwWindowShouldClose(window)) {
        main_loop();
    }
}


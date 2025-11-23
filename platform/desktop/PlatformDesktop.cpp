//
// Created by ju on 11/19/25.
//

#include "PlatformDesktop.hpp"
#include <iostream>


std::filesystem::path PlatformDesktop::resolveAssetPath(const std::filesystem::path &relativeAssetPath) {
    auto mergedPath = ("./assets" / relativeAssetPath).make_preferred();
    return std::filesystem::canonical(mergedPath);
}



void PlatformDesktop::do_main_loop(const std::function<void()>& func) {
    while(!global_backend->window->should_close()) {
        func();
    }
}

PlatformDesktop::PlatformDesktop() {
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD\n";
    }
}

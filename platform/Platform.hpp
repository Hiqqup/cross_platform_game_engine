//
// Created by ju on 11/19/25.
//

#pragma once
#include "GlfwWindow.hpp"
#include <filesystem>
#include <functional>

class Platform {
    GlfwWindow glfw_window;
public:
    cpge::Window* window = &glfw_window;
    virtual ~Platform() = default;
    virtual void do_main_loop(const std::function<void()>& callback) = 0;
    virtual std::filesystem::path resolve_asset_path(const std::filesystem::path &relativeAssetPath) = 0 ;
};
extern Platform* global_backend;
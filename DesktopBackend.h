//
// Created by ju on 11/19/25.
//

#pragma once
#include "Backend.h"
#include <GLFW/glfw3.h>


class DesktopBackend: public Backend {
public:
    void initialize_context() override;
    std::filesystem::path resolveAssetPath(const std::filesystem::path &relativeAssetPath) override;
    void do_main_loop(const std::function<void()> &func) override;
};

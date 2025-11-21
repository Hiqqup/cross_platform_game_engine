//
// Created by ju on 11/19/25.
//

#pragma once
#include "Backend.h"
#include <GLFW/glfw3.h>


class BrowserBackend: public Backend {
public:

    std::filesystem::path resolveAssetPath(const std::filesystem::path &relativeAssetPath) override;
    void do_main_loop(const std::function<void()> &func) override;
};

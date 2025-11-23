//
// Created by ju on 11/19/25.
//

#pragma once
#include "../Platform.hpp"


class PlatformBrowser final: public Platform {
public:
    void do_main_loop(const std::function<void()> &callback) override;
    std::filesystem::path resolve_asset_path(const std::filesystem::path &relativeAssetPath) override;
};

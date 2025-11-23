//
// Created by ju on 11/19/25.
//

#pragma once
#include "../Platform.hpp"


class PlatformDesktop final : public Platform {
public:
    PlatformDesktop();
    void do_main_loop(const std::function<void()> &func) override;
    std::filesystem::path resolve_asset_path(const std::filesystem::path &relativeAssetPath) override;
};

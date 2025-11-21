//
// Created by ju on 11/19/25.
//

#include "BrowserBackend.h"
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include "gl_backend.h"
#include <iostream>



std::filesystem::path BrowserBackend::resolveAssetPath(const std::filesystem::path &relativeAssetPath) {
    return std::filesystem::path("/assets") / relativeAssetPath;
}


void BrowserBackend::do_main_loop(const std::function<void()>& func) {
    emscripten_set_main_loop_arg([](void* arg) {
            auto* backend = static_cast<BrowserBackend *>(arg);
            backend->main_loop();
        }, this, 0, true);
}

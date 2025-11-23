//
// Created by ju on 11/23/25.
//

#pragma once
#include <glm/vec2.hpp>

namespace cpge {
    class Window  {
    public:
        virtual ~Window() = default;
        virtual bool should_close() = 0;
        virtual void update() =0;
        [[nodiscard]] virtual glm::vec2 get_window_size() = 0;
        virtual void set_cursor_disabled(bool value) = 0;
    };
}
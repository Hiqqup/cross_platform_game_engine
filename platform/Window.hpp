//
// Created by ju on 11/23/25.
//

#pragma once


namespace cpge {
    class Window  {
    public:
        virtual ~Window() = default;
        virtual bool should_close() = 0;
        virtual void update() =0;
    };
}
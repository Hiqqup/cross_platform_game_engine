//
// Created by ju on 11/19/25.
//

#pragma once
#include <GLES3/gl3.h>
#include <string>


class Backend {
public:
    virtual void initialize_context() = 0;
    virtual void init() = 0;
    virtual void do_main_loop() = 0;
    virtual void cleanup() = 0;
};

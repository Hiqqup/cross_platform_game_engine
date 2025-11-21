//
// Created by ju on 11/21/25.
//

#pragma once

#include "gl_backend.h"
#include <filesystem>


class Shader {
    GLuint shaderProgram, vertexShader, fragmentShader;
public:
    void use();
    Shader(const std::filesystem::path& full_vertex_path, const std::filesystem::path& full_fragment_path);
    ~Shader();
    void passUniform(const std::string & uniform_name, int value);
};
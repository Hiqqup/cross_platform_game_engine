//
// Created by ju on 11/21/25.
//

#pragma once

#include <glm/glm.hpp>
#include "gl_backend.hpp"

#include <filesystem>


class Shader {
    GLuint shader_program, vertex_shader, fragment_shader;
public:
    void use();
    Shader(const std::filesystem::path& full_vertex_path, const std::filesystem::path& full_fragment_path);
    ~Shader();
    void pass_uniform(const std::string & uniform_name, int value);
    void pass_uniform(const std::string & uniform_name, const glm::mat4& value);
};
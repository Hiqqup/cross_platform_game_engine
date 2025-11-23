//
// Created by ju on 11/21/25.
//

#include "Shader.hpp"
#include "platform/Platform.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::string readText(const std::filesystem::path &filePath) {
    std::ifstream sourceFile(filePath);
    if (!sourceFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    std::stringstream buffer;
    buffer << sourceFile.rdbuf();
    return buffer.str();
}

void handle_shader_compilation_error(const GLuint shaderID) {
    GLint success = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if (!success) {
        GLint logLength = 0;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);

        std::string infoLog;
        infoLog.resize(logLength);

        glGetShaderInfoLog(shaderID, logLength, nullptr, infoLog.data());

        glDeleteShader(shaderID);

        throw std::runtime_error(
            "Shader compile error:\n" + infoLog
        );
    }
}
 GLuint loadAndCompileShader(GLuint shaderType, const std::filesystem::path &shaderPath) {
     auto shaderSource = readText(shaderPath);
     auto source = shaderSource.c_str();
     auto shaderID = glCreateShader(shaderType);
     glShaderSource(shaderID, 1, &source, nullptr);
     glCompileShader(shaderID);
    handle_shader_compilation_error(shaderID);

    return shaderID;
 }

void Shader::use() {
    glUseProgram(shaderProgram);
}

Shader::Shader(const std::filesystem::path &full_vertex_path, const std::filesystem::path &full_fragment_path) {
    GLuint vertexShader = loadAndCompileShader(GL_VERTEX_SHADER, full_vertex_path);
    GLuint fragmentShader =loadAndCompileShader(GL_FRAGMENT_SHADER, full_fragment_path);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


Shader::~Shader() {
    glDeleteProgram(shaderProgram);
}

void Shader::passUniform(const std::string &uniform_name, int value) {
    glUniform1i(glGetUniformLocation(shaderProgram, uniform_name.c_str()), value);
}

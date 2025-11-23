//
// Created by ju on 11/20/25.
//

#include "Image.hpp"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Image::Image(const std::filesystem::path &full_image_path) {
    int  nrChannels;
    const char* texture_path = full_image_path.c_str();
    data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Failed to load image";
    }
}

Image::~Image() {
    stbi_image_free(data);
}

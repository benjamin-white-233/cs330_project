//
// Created by Ben White on 2/4/23.
//
#pragma once
#include <filesystem>
#include <glad/glad.h>

class Texture {
public:
    explicit Texture(const std::filesystem::path& path);
    void Bind();

private:
    GLuint _textureHandle;
};



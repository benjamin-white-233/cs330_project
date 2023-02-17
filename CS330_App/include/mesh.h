#pragma once
#include <vector>
#include <types.h>
#include <glad/glad.h>
#include <string>

class Mesh {
public:
    Mesh(std::string name, std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);

    void Draw();
    std::string GetName();

    glm::mat4 Transform {1.f};

private:
    void init(std::string name, std::vector<Vertex>& vertices, std::vector<uint32_t>& elements);

private:
    std::string _name;
    uint32_t _elementCount {0};
    GLuint _vertexBufferObject {};
    GLuint _shaderProgram {};
    GLuint _vertexArrayObject {};
    GLuint _elementBufferObject {};
};
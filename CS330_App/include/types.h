#pragma once
#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 Position {0.f, 0.f, 0.f};
    glm::vec3 Color {1.f, 1.f, 1.f};
    glm::vec3 Normal {0.f, 0.f, 0.f};
    glm::vec2 Uv {1.f, 1.f};
};


struct Shapes {
    static inline void UpdateNormals(Vertex& p1, Vertex& p2, Vertex& p3) {
        glm::vec3 U = p2.Position - p1.Position;
        glm::vec3 V = p3.Position - p1.Position;

        auto normal = glm::cross(U, V);

        p1.Normal = normal;
        p2.Normal = normal;
        p3.Normal = normal;
    };

    static inline std::vector<Vertex> sphereVertices(int stacks, int slices, float color_x, float color_y, float color_z) {
        const float PI = 3.14159265359f;

        std::vector<Vertex> vertices;
        std::vector<uint32_t> elements;

        // loop through stacks.
        for (int i = 0; i <= stacks; ++i){

            Vertex vertex;
            float V = (float) i / (float) stacks;
            float phi = V * PI;

            // loop through the slices.
            for (int j = 0; j <= slices; ++j) {

                float U = (float) j / (float) slices;
                float theta = U * (PI * 2);

                // use spherical coordinates to calculate the positions.
                float x = cos(theta) * sin(phi);
                float y = cos(phi);
                float z = sin(theta) * sin(phi);

                vertex.Position.x = x;
                vertex.Position.y = y;
                vertex.Position.z = z;

                vertex.Color.x = color_x;
                vertex.Color.y = color_y;
                vertex.Color.z = color_z;

                vertices.push_back(vertex);
            }
        }
        return vertices;
    };

    static inline std::vector<uint32_t> sphereElements(int stacks, int slices) {
        std::vector<uint32_t> elements;

        for (int i = 0; i < slices * stacks + slices; ++i){
            elements.push_back((i));
            elements.push_back((i + slices + 1));
            elements.push_back((i + slices));

            elements.push_back((i + slices + 1));
            elements.push_back((i));
            elements.push_back((i + 1));
        }
        return elements;
    }

    static inline std::vector<Vertex> planeVertices {
            // 0
            {
                    .Position = {-2.5f, 0.f, 4.f},
                    .Color = {0.3f, 0.371f, 0.5f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 1
            {
                    .Position = {2.5f, 0.f, 4.f},
                    .Color = {0.3f, 0.371f, 0.5f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // 2
            {
                    .Position = {2.5f, 0.f, -4.f},
                    .Color = {0.3f, 0.371f, 0.5f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 3
            {
                    .Position = {-2.5f, 0.f, -4.f},
                    .Color = {0.3f, 0.371f, 0.5f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
    };

    static inline std::vector<Vertex> bridgePillarVertices {
            // front
            // 0
            {
                    .Position = {-0.25f, 0.9f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 1
            {
                    .Position = {-0.25f, -0.5f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 2
            {
                    .Position = {0.25f, -0.5f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 3
            {
                    .Position = {0.25f, 0.9f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f},
            },
            // right
            // 4
            {
                    .Position = {0.25f, 0.9f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 5
            {
                    .Position = {0.25f, -0.5f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 6
            {
                    .Position = {0.25f, -0.5f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 7
            {
                    .Position = {0.25f, 0.9f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f},
            },
            // back
            // 8
            {
                    .Position = {0.25f, 0.9f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 9
            {
                    .Position = {0.25f, -0.5f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 10
            {
                    .Position = {-0.25f, -0.5f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 11
            {
                    .Position = {-0.25f, 0.9f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // left
            // 12
            {
                    .Position = {-0.25f, 0.9f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 13
            {
                    .Position = {-0.25f, -0.5f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 14
            {
                    .Position = {-0.25f, -0.5f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 15
            {
                    .Position = {-0.25f, 0.9f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // top
            // 16
            {
                    .Position = {-0.25f, 0.9f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 17
            {
                    .Position = {-0.25f, 0.9f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 18
            {
                    .Position = {0.25f, 0.9f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 19
            {
                    .Position = {0.25f, 0.9f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // bottom
            // 20
            {
                    .Position = {0.25f, -0.5f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 21
            {
                    .Position = {0.25f, -0.5f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 22
            {
                    .Position = {-0.25f, -0.5f, -0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // 23
            {
                    .Position = {-0.25f, -0.5f, 0.5f},
                    .Color = {0.212f, 0.212f, 0.212f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
    };

    static inline std::vector<Vertex> bridgeBodyVertices {
            // front
            // 0
            {
                    .Position = {-0.75f, 0.25f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 1
            {
                    .Position = {-0.75f, -0.5f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 2
            {
                    .Position = {0.75f, -0.5f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 3
            {
                    .Position = {0.75f, 0.25f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // right
            // 4
            {
                    .Position = {0.75f, 0.25f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 5
            {
                    .Position = {0.75f, -0.5f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 6
            {
                    .Position = {0.75f, -0.5f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 7
            {
                    .Position = {0.75f, 0.25f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // back
            // 8
            {
                    .Position = {0.75f, 0.25f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 9
            {
                    .Position = {0.75f, -0.5f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 10
            {
                    .Position = {-0.75f, -0.5f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 11
            {
                    .Position = {-0.75f, 0.25f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // left
            // 12
            {
                    .Position = {-0.75f, 0.25f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 13
            {
                    .Position = {-0.75f, -0.5f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 14
            {
                    .Position = {-0.75f, -0.5f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 15
            {
                    .Position = {-0.75f, 0.25f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // top
            // 16
            {
                    .Position = {-0.75f, 0.25f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
            },
            // 17
            {
                    .Position = {-0.75f, 0.25f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
            },
            // 18
            {
                    .Position = {0.75f, 0.25f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
            },
            // 19
            {
                    .Position = {0.75f, 0.25f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
            },
            // bottom
            // 20
            {
                    .Position = {0.75f, -0.5f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 21
            {
                    .Position = {0.75f, -0.5f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}

            },
            // 22
            {
                    .Position = {-0.75f, -0.5f, -0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 23
            {
                    .Position = {-0.75f, -0.5f, 0.5f},
                    .Color = {0.6f, 0.3f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
    };

    static inline std::vector<Vertex> bridgeTopVertices{
            /// first triangle
            // front
            // 0
            {
                    .Position = {-1.f, -0.5f, 1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 1
            {
                    .Position = {1.f, -0.5f, 1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // top point
            // 2
            {
                    .Position = {0.0f, 0.1f, 1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            //// second triangle
            // front
            // 3
            {
                    .Position = {-1.f, -0.5f, -1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 4
            {
                    .Position = {1.f, -0.5f, -1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // top point
            // 5
            {
                    .Position = {0.0f, 0.1f, -1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // triangle 1 texture
            // 6
            {
                    .Position = {-1.f, -0.5f, -1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 7
            {
                    .Position = {1.0f, -0.5f, -1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // front
            // 8
            {
                    .Position = {0.f, 0.1f, -1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.5f, 1.f}
            },
            // triangle 2 texture
            // 9
            {
                    .Position = {-1.f, -0.5f, 1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 10
            {
                    .Position = {1.0f, -0.5f, 1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // front
            // 11
            {
                    .Position = {0.f, 0.1f, 1.25f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.5f, 1.f}
            },
            // base texture
            // 12
            {
                    .Position = {-1.f, -0.51f, -1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 13
            {
                    .Position = {-1.f, -0.51f, 1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // 14
            {
                    .Position = {1.0f, -0.51f, -1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 15
            {
                    .Position = {1.0f, -0.51f, 1.251f},
                    .Color = {0.3f, 0.1f, 0.000f},
                    .Normal = {0.f, 0.f, 0.f},
                    .Uv = {1.f, 1.f}
            },

    };

    static inline std::vector<Vertex> cubeVertices{
            // front
            // 0
            {
                    .Position = {-0.5f, 0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f},
                    .Uv = {0.f, 0.f}
            },
            // 1
            {
                    .Position = {-0.5f, -0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f},
                    .Uv = {1.f, 0.f}
            },
            // 2
            {
                    .Position = {0.5f, -0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f},
                    .Uv = {1.f, 1.f}
            },
            // 3
            {
                    .Position = {0.5f, 0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f},
                    .Uv = {0.f, 1.f}
            },
            // right
            // 4
            {
                    .Position = {0.5f, 0.5f, 0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Uv = {0.f, 0.f}
            },
            // 5
            {
                    .Position = {0.5f, -0.5f, 0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Uv = {1.f, 0.f}
            },
            // 6
            {
                    .Position = {0.5f, -0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Uv = {1.f, 1.f}
            },
            // 7
            {
                    .Position = {0.5f, 0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Uv = {0.f, 1.f}
            },
            // back
            // 8
            {
                    .Position = {0.5f, 0.5f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f},
                    .Uv = {0.f, 0.f}
            },
            // 9
            {
                    .Position = {0.5f, -0.5f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f},
                    .Uv = {1.f, 0.f}
            },
            // 10
            {
                    .Position = {-0.5f, -0.5f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f},
                    .Uv = {1.f, 1.f}
            },
            // 11
            {
                    .Position = {-0.5f, 0.5f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f},
                    .Uv = {0.f, 1.f}
            },
            // left
            // 12
            {
                    .Position = {-0.5f, 0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 13
            {
                    .Position = {-0.5f, -0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {1.f, 0.f}
            },
            // 14
            {
                    .Position = {-0.5f, -0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 15
            {
                    .Position = {-0.5f, 0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // top
            // 16
            {
                    .Position = {-0.5f, 0.5f, -0.5f},
                    .Color = {0.f, 1.f, 0.f},
                    .Uv = {0.f, 0.f}

            },
            // 17
            {
                    .Position = {-0.5f, 0.5f, 0.5f},
                    .Color = {0.f, 1.f, 0.f},
                    .Uv = {1.f, 0.f}

            },
            // 18
            {
                    .Position = {0.5f, 0.5f, 0.5f},
                    .Color = {0.f, 1.f, 0.f},
                    .Uv = {1.f, 1.f}

            },
            // 19
            {
                    .Position = {0.5f, 0.5f, -0.5f},
                    .Color = {0.f, 1.f, 0.f},
                    .Uv = {0.f, 1.f}
            },
            // bottom
            // 20
            {
                    .Position = {0.5f, -0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {0.f, 0.f}
            },
            // 21
            {
                    .Position = {0.5f, -0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {1.f, 0.f}

            },
            // 22
            {
                    .Position = {-0.5f, -0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {1.f, 1.f}
            },
            // 23
            {
                    .Position = {-0.5f, -0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f},
                    .Uv = {0.f, 1.f}
            },
    };

    static inline std::vector<Vertex> pyramidVertices{
            // front
            // 0
            {
                    .Position = {-0.5f, -0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {0.f, 0.f}
            },
            // 1
            {
                    .Position = {0.5f, -0.5f, 0.5f},
                    .Color = {0.5f, 1.f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {1.f, 0.f}
            },
            // top point
            // 2
            {
                    .Position = {0.0f, 0.5f, 0.0f},
                    .Color = {0.5f, 0.5f, 1.f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {0.5f, 1.f}
            },
            // right
            // 3
            {
                    .Position = {0.5f, -0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {0.f, 0.f}
            },
            // 4
            {
                    .Position = {-0.5f, -0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {1.f, 0.f}
            },

            // base
            // 5 = 0
            {
                    .Position = {-0.5f, -0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {0.f, 0.f}
            },
            // 6 = 1
            {
                    .Position = {0.5f, -0.5f, 0.5f},
                    .Color = {0.5f, 1.f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {1.f, 0.f}
            },
            // 7 = 2
            {
                    .Position = {0.5f, -0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {1.f, 1.f}
            },
            // 8 = 3
            {
                    .Position = {-0.5f, -0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f},
                    .Normal = {0.0f, 0.0f, 0.0f},
                    .Uv = {0.f, 1.f}
            },
    };

    static inline std::vector<uint32_t> pyramidElements{
            // sides
            0, 1, 2,
            1, 3, 2,
            3, 4, 2,
            4, 0, 2,
            // base
            5, 6, 7,
            7, 8, 5
    };

    static inline std::vector<uint32_t> bridgeTopElements {
            // first triangle
            0, 1, 2,
            // second triangle
            3, 5, 4,
            // sides
            1, 4, 5,
            1, 5, 2,
            0, 2, 5,
            0, 5, 3,
            // base
            1, 3, 4,
            0, 1, 3,
            // triangle texture
            6, 7, 8,
            9, 10, 11,
            // base texture
            12, 13, 14,
            13, 14, 15
    };


    static inline std::vector<uint32_t> cubeElements {
            0, 1, 3, 1, 2, 3, // front
            4, 5, 7, 5, 6, 7, // right
            8, 9, 11, 9, 10, 11, // back
            12, 13, 15, 13, 14, 15, // left
            16, 17, 19, 17, 18, 19, // top
            20, 21, 23, 21, 22, 23 // bottom
    };

    static inline std::vector<uint32_t> bridgeBodyElements {
            0, 1, 3, 1, 2, 3, // front
            4, 5, 7, 5, 6, 7, // right
            8, 9, 11, 9, 10, 11, // back
            12, 13, 15, 13, 14, 15, // left
            16, 17, 19, 17, 18, 19, // top
            20, 21, 23, 21, 22, 23 // bottom
    };

    static inline std::vector<uint32_t> bridgePillarElements {
            0, 1, 3, 1, 2, 3, // front
            4, 5, 7, 5, 6, 7, // right
            8, 9, 11, 9, 10, 11, // back
            12, 13, 15, 13, 14, 15, // left
            16, 17, 19, 17, 18, 19, // top
            20, 21, 23, 21, 22, 23 // bottom
    };

    static inline std::vector<uint32_t> planeElements {
            0, 1, 2,
            2, 3, 0
    };
};
#pragma once
#include <glm/glm.hpp>


struct Vertex {
    glm::vec3 Position {0.f, 0.f, 0.f};
    glm::vec3 Color {1.f, 1.f, 1.f};
    glm::vec3 Normal {0.f, 0.f, 0.f};
    glm::vec2 Uv {1.f, 1.f};
};


struct Shapes {
    static inline std::vector<Vertex> cubeVertices {
    // front
        // 0
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f}
        },
        // 1
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f}
        },
        // 2
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f}

        },
        // 3
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f}
        },
    // right
        // 4
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f}
        },
        // 5
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f}
        },
        // 6
        {
            .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f}
        },
        // 7
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f}
        },
    // back
        // 8
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f}
        },
        // 9
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f}
        },
        // 10
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f}
        },
        // 11
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f}
        },
    // left
        // 12
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
        // 13
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
        // 14
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
        // 15
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
    // top
        // 16
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f}
        },
        // 17
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f}
        },
        // 18
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f}
        },
        // 19
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f}
        },
    // bottom
        // 20
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
        // 21
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f}

        },
        // 23
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
        // 23
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f}
        },
    };

    static inline std::vector<uint32_t> cubeElements {
        0, 1, 3, 1, 2, 3, // front
        4, 5, 7, 5, 6, 7, // right
        8, 9, 11, 9, 10, 11, // back
        12, 13, 15, 13, 14, 15, // left
        16, 17, 19, 17, 18, 19, // top
        20, 21, 23, 21, 22, 23 // bottom

    };

    static inline std::vector<Vertex> pyramidVertices {
            // front
            // 0
            {
                    .Position = {-0.5f, -0.5f, -0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 1
            {
                    .Position = {0.5f, -0.5f, -0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // top point
            // 2
            {
                    .Position = {0.0f, 0.5f, 0.0f},
                    .Color = {0.5f, 0.5f, 1.f}

            },
            // right
            // 3
            {
                    .Position = {0.5f, -0.5f, 0.5f},
                    .Color = {0.5f, 0.5f, 0.5f}
            },
            // 4
            {
                    .Position = {-0.5f, -0.5f, 0.5f},
                    .Color = {0.5f, 0.5f, 0.5f}
            },
    };

    static inline std::vector<uint32_t> pyramidElements {
           0, 1, 2,
           1, 3, 2,
           3, 4, 2,
           4, 0, 2,
           0, 3, 2,
           0, 3, 4,
           0, 1, 3
    };
};
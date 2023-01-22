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

    static inline std::vector<Vertex> bridgePillarVertices {
            // front
            // 0
            {
                    .Position = {-0.25f, 1.f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 1
            {
                    .Position = {-0.25f, -0.75f, 0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // 2
            {
                    .Position = {0.25f, -0.75f, 0.5f},
                    .Color = {0.5f, 0.5f, 1.f}

            },
            // 3
            {
                    .Position = {0.25f, 1.f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // right
            // 4
            {
                    .Position = {0.25f, 1.f, 0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // 5
            {
                    .Position = {0.25f, -0.75f, 0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // 6
            {
                    .Position = {0.25f, -0.75f, -0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 7
            {
                    .Position = {0.25f, 1.f, -0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // back
            // 8
            {
                    .Position = {0.25f, 1.f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // 9
            {
                    .Position = {0.25f, -0.75f, -0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 10
            {
                    .Position = {-0.25f, -0.75f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // 11
            {
                    .Position = {-0.25f, 1.f, -0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // left
            // 12
            {
                    .Position = {-0.25f, 1.f, -0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // 13
            {
                    .Position = {-0.25f, -0.75f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // 14
            {
                    .Position = {-0.25f, -0.75f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 15
            {
                    .Position = {-0.25f, 1.f, 0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // top
            // 16
            {
                    .Position = {-0.25f, 1.f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // 17
            {
                    .Position = {-0.25f, 1.f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 18
            {
                    .Position = {0.25f, 1.f, 0.5f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // 19
            {
                    .Position = {0.25f, 1.f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // bottom
            // 20
            {
                    .Position = {0.25f, -0.75f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 21
            {
                    .Position = {0.25f, -0.75f, -0.5f},
                    .Color = {0.5f, 1.f, 0.5f}

            },
            // 22
            {
                    .Position = {-0.25f, -0.75f, -0.5f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            // 23
            {
                    .Position = {-0.25f, -0.75f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
    };

    static inline std::vector<Vertex> bridgeBodyVertices {
            // front
            // 0
            {
                    .Position = {-1.f, 0.25f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 1
            {
                    .Position = {-1.f, -0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 2
            {
                    .Position = {1.f, -0.5f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}

            },
            // 3
            {
                    .Position = {1.f, 0.25f, 0.5f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // right
            // 4
            {
                    .Position = {1.f, 0.25f, 0.5f},
                    .Color = {0.5f, 0.5f, 0.5f}
            },
            // 5
            {
                    .Position = {1.f, -0.5f, 0.5f},
                    .Color = {0.5f, 0.5f, 0.5f}
            },
            // 6
            {
                    .Position = {1.f, -0.5f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f}
            },
            // 7
            {
                    .Position = {1.f, 0.25f, -0.5f},
                    .Color = {0.5f, 0.5f, 0.5f}
            },
            // back
            // 8
            {
                    .Position = {1.f, 0.25f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f}
            },
            // 9
            {
                    .Position = {1.f, -0.5f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f}
            },
            // 10
            {
                    .Position = {-1.f, -0.5f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f}
            },
            // 11
            {
                    .Position = {-1.f, 0.25f, -0.5f},
                    .Color = {1.f, 1.f, 0.5f}
            },
            // left
            // 12
            {
                    .Position = {-1.f, 0.25f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
            // 13
            {
                    .Position = {-1.f, -0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
            // 14
            {
                    .Position = {-1.f, -0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
            // 15
            {
                    .Position = {-1.f, 0.25f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
            // top
            // 16
            {
                    .Position = {-1.f, 0.25f, -0.5f},
                    .Color = {0.f, 1.f, 0.f}
            },
            // 17
            {
                    .Position = {-1.f, 0.25f, 0.5f},
                    .Color = {0.f, 1.f, 0.f}
            },
            // 18
            {
                    .Position = {1.f, 0.25f, 0.5f},
                    .Color = {0.f, 1.f, 0.f}
            },
            // 19
            {
                    .Position = {1.f, 0.25f, -0.5f},
                    .Color = {0.f, 1.f, 0.f}
            },
            // bottom
            // 20
            {
                    .Position = {1.f, -0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
            // 21
            {
                    .Position = {1.f, -0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f}

            },
            // 22
            {
                    .Position = {-1.f, -0.5f, -0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
            // 23
            {
                    .Position = {-1.f, -0.5f, 0.5f},
                    .Color = {0.f, 0.5f, 0.f}
            },
    };

    static inline std::vector<Vertex> bridgeTopVertices{
            /// first triangle
            // front
            // 0
            {
                    .Position = {-1.f, -0.5f, -1.25f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 1
            {
                    .Position = {1.f, -0.5f, -1.25f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // top point
            // 2
            {
                    .Position = {0.0f, 0.1f, -1.25f},
                    .Color = {0.5f, 0.5f, 1.f}
            },
            //// second triangle
            // front
            // 3
            {
                    .Position = {1.f, -0.5f, 1.25f},
                    .Color = {1.f, 0.5f, 0.5f}
            },
            // 4
            {
                    .Position = {-1.f, -0.5f, 1.25f},
                    .Color = {0.5f, 1.f, 0.5f}
            },
            // top point
            // 5
            {
                    .Position = {0.0f, 0.1f, 1.25f},
                    .Color = {0.5f, 0.5f, 1.f}
            }
    };

    static inline std::vector<uint32_t> bridgeTopElements {
            0, 1, 2,
            3, 4, 5,
            0, 1, 3,
            3, 1, 4,
            1, 2, 4,
            4, 2, 5,
            2, 0, 5,
            5, 0, 3,
            0, 4, 2
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
};
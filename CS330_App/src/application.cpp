#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <stb_image.h>

Application::Application(std::string WindowTitle, int width, int height)
        : _applicationName{ WindowTitle }, _width{ width }, _height{ height },
          _camera {width, height, {-2.f, 0.f, 5.f}, true },
          _cameraLookSpeed {0.1f, 0.1f}
{}

void Application::Run() {
    // Open the window
    if (!openWindow()) {
        return;
    }

    setupInputs();
    _running = true;

    // Set up the scene
    setupScene();

    // Run application
    while (_running) {
        float currentTime = glfwGetTime();

        if (_lastFrameTime == -1.f) {
            _lastFrameTime = currentTime;
        }

        auto deltaTime = currentTime - _lastFrameTime;
        _lastFrameTime = currentTime;

        if (glfwWindowShouldClose(_window)) {
            _running = false;
            continue;
        }
        // Update
        update(deltaTime);
        // Draw
        draw();
    }
    glfwTerminate();
}

bool Application::openWindow() {
    // initialize glad to v3.3
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // creating the window, 800x600
    _window = glfwCreateWindow(800, 600, "Benjamin White", nullptr, nullptr);

    if (!_window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
    }

    // sets _widow to the current thread
    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, (void*)this);

    // adjusting the viewport if window is resized
    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);

        auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
        app->_width = width;
        app->_height = height;

        app->_camera.SetSize(width, height);
    });

    // if GLAD cannot be loaded, return false
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    // cull back faces to ensure correct vertices ordering
//    glFrontFace(GL_CCW);
//    glCullFace(GL_BACK);
//    glEnable(GL_CULL_FACE);

    // otherwise, return true
    return true;
}


void Application::setupInputs() {
    glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

        // establishing key press actions
        switch (key) {
            case GLFW_KEY_ESCAPE: {
                if (action == GLFW_PRESS) {
                    app->_running = false;
                }
                break;
            }
                // switch to ortho camera
            case GLFW_KEY_P: {
                if (action == GLFW_PRESS) {
                    app->_camera.SetIsPerspective(!app->_camera.IsPerspective());
                }
            }
            default: {}
        }
    });

    glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xpos, double ypos) {
        auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

        app->mousePositionCallback(xpos, ypos);
    });

    glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) {
        auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

        app->IncrementSpeed(yOffset);

        std::cout << "Mouse wheel (" << xOffset << ", " << yOffset << ")" << std::endl;
    });

    glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
        switch (button) {
            case GLFW_MOUSE_BUTTON_LEFT: {
                if (action == GLFW_PRESS) {
                    std::cout << "Mouse button left pressed" << std::endl;
                }
                else {

                }
                break;
            }
            case GLFW_MOUSE_BUTTON_MIDDLE: {
                if (action == GLFW_PRESS) {
                    std::cout << "Mouse button middle pressed" << std::endl;
                }
                else {

                }
                break;
            }
            case GLFW_MOUSE_BUTTON_RIGHT: {
                if (action == GLFW_PRESS) {
                    std::cout << "Mouse button right pressed" << std::endl;
                }
                else {

                }
                break;
            }
            default:
                std::cout << "Unhangled mouse button event" << std::endl;
        }
    });
}

void Application::setupScene() {
    //// shapes
    // creating different meshes for each shape and manipulating the position
    auto &river = _meshes.emplace_back("river", Shapes::riverVertices, Shapes::planeElements);
    river.Transform = glm::translate(river.Transform, glm::vec3(0.f, -1.f, 0.f));

    auto &grass = _meshes.emplace_back("grass", Shapes::planeVertices, Shapes::planeElements);
    grass.Transform = glm::translate(grass.Transform, glm::vec3(0.f, -1.001f, 0.f));
    grass.Transform = glm::scale(grass.Transform, glm::vec3(2.f));

    auto &bridgePillar1 = _meshes.emplace_back("bridgePillar1", Shapes::bridgePillarVertices, Shapes::bridgePillarElements);
    bridgePillar1.Transform = glm::translate(bridgePillar1.Transform, glm::vec3(1.5f, -0.5f, 0.0f));

    auto &bridgePillar2 = _meshes.emplace_back("bridgePillar2", Shapes::bridgePillarVertices, Shapes::bridgePillarElements);
    bridgePillar2.Transform = glm::translate(bridgePillar2.Transform, glm::vec3(-1.f, -0.5f, 0.0f));

    auto &bridgeTop = _meshes.emplace_back("bridgeTop", Shapes::bridgeTopVertices, Shapes::bridgeTopElements);
    bridgeTop.Transform = glm::translate(bridgeTop.Transform, glm::vec3(0.0f, 0.90f, 0.0f));
    bridgeTop.Transform = glm::rotate(bridgeTop.Transform, glm::radians(90.f), glm::vec3(0, 1, 0));

    auto &bridgeBody = _meshes.emplace_back("bridgeBody", Shapes::bridgeBodyVertices, Shapes::cubeElements);
    bridgeBody.Transform = glm::translate(bridgeBody.Transform, glm::vec3(0.0f, 0.25f, 0.0f));

    //// lights
    std::vector<Vertex> sunVertices = Shapes::sphereVertices(100, 100, 1.f, 1.f, 0.95f);
    std::vector<uint32_t> sunElements = Shapes::sphereElements(100, 100);

    auto &sun = _lights.emplace_back(sunVertices, sunElements);
    sun.Transform = glm::translate(sun.Transform, glm::vec3(4.f, 3.f, -10.f));
    sun.Transform = glm::scale(sun.Transform, glm::vec3(2.f));


    // declaring paths to shaderfiles
    Path shaderPath = std::filesystem::current_path() / "assets" / "shaders";
    _lighting_shader = Shader(shaderPath / "basic_lighting.vert", shaderPath / "basic_lighting.frag");
    _light_cube_shader = Shader(shaderPath / "sun_light.vert", shaderPath / "sun_light.frag");

    //// textures
    auto texturePath = std::filesystem::current_path() / "assets" / "textures";
    _textures.emplace_back(texturePath / "wood.jpeg"); // 0
    _textures.emplace_back(texturePath / "moss.jpg"); // 1
    _textures.emplace_back(texturePath / "water4.png"); // 2
    _textures.emplace_back(texturePath / "stone.jpg"); // 3
    _textures.emplace_back(texturePath / "steel.jpg"); // 4
    _textures.emplace_back(texturePath / "sun.jpg"); // 5
    _textures.emplace_back(texturePath / "grass.jpg"); // 6
}

bool Application::update(float deltaTime) {
    glfwPollEvents();

    handleInput(deltaTime);

    return false;
}

bool Application::draw() {
    // background color
    glClearColor(0.6f, 0.8f, 1.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // camera
    // set model view projection matrix
    glm::mat4 view = _camera.GetViewMatrix();
    glm::mat4 projection = _camera.GetProjectionMatrix();

    for (auto &light: _lights) {
        // set matrices in the shader
        _light_cube_shader.Bind();
        _light_cube_shader.SetMat4("projection", projection);
        _light_cube_shader.SetMat4("view", view);
        _light_cube_shader.SetMat4("model", light.Transform);

        _light_cube_shader.SetVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
        _light_cube_shader.SetVec3("lightPos", glm::vec3(light.Transform[3]));
        _light_cube_shader.SetVec3("viewPos", _camera.position);

        light.Draw();
    }

    _lighting_shader.SetInt("tex0", 0);
    _lighting_shader.SetInt("tex1", 1);

    int counter = 0;
    // draw each mesh
    for (auto &mesh: _meshes) {
        // set matrices in the shader
        _lighting_shader.Bind();
        // send position of light source to object shader
        _lighting_shader.SetVec3("lightPos", glm::vec3(_lights[counter].Transform[3]));
        _lighting_shader.SetVec3("viewPos", _camera.position);
        _lighting_shader.SetMat4("projection", projection);
        _lighting_shader.SetMat4("view", view);
        // sending each individual mesh.Transform to the shader
        _lighting_shader.SetMat4("model", mesh.Transform);

        if (counter < _lights.size()) {
            counter += 1;
        }

        if (mesh.GetName() == "river") {
            glActiveTexture(GL_TEXTURE0);
            _textures[2].Bind(); // water
            glActiveTexture(GL_TEXTURE1);
            _textures[2].Bind(); // water
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }

        if (mesh.GetName() == "grass") {
            glActiveTexture(GL_TEXTURE0);
            _textures[6].Bind(); // grass
            glActiveTexture(GL_TEXTURE1);
            _textures[6].Bind(); // grass
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }

        if (mesh.GetName() == "bridgeTop") {
            glActiveTexture(GL_TEXTURE0);
            _textures[4].Bind(); // steel
            glActiveTexture(GL_TEXTURE1);
            _textures[4].Bind(); // steel
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }
        if (mesh.GetName() == "bridgePillar1") {
            glActiveTexture(GL_TEXTURE0);
            _textures[3].Bind(); // moss
            glActiveTexture(GL_TEXTURE1);
            _textures[1].Bind(); // stone
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }
        if (mesh.GetName() == "bridgePillar2") {
            glActiveTexture(GL_TEXTURE0);
            _textures[3].Bind(); // stone
            glActiveTexture(GL_TEXTURE1);
            _textures[1].Bind(); // moss
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }

        if (mesh.GetName() == "bridgeBody") {
            glActiveTexture(GL_TEXTURE0);
            _textures[0].Bind(); // wood
            glActiveTexture(GL_TEXTURE1);
            _textures[1].Bind(); // moss
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }

        if (mesh.GetName() == "rock") {
            glActiveTexture(GL_TEXTURE0);
            _textures[3].Bind(); // stone
            glActiveTexture(GL_TEXTURE1);
            _textures[3].Bind(); // stone
            mesh.Draw();
            glDisable(GL_TEXTURE_2D);
        }
    }

    glfwSwapBuffers(_window);
    return false;
}


// assigning keys to a movement direction
void Application::handleInput(float deltaTime) {

    auto moveAmount = abs(_moveSpeed * deltaTime);

    if (glfwGetKey(_window, GLFW_KEY_W)) {
        _camera.MoveCamera(Camera::MoveDirection::Forward, moveAmount);
    }
    if (glfwGetKey(_window, GLFW_KEY_A)) {
        _camera.MoveCamera(Camera::MoveDirection::Left, moveAmount);
    }
    if (glfwGetKey(_window, GLFW_KEY_S)) {
        _camera.MoveCamera(Camera::MoveDirection::Backward, moveAmount);
    }
    if (glfwGetKey(_window, GLFW_KEY_D)) {
        _camera.MoveCamera(Camera::MoveDirection::Right, moveAmount);
    }
    if (glfwGetKey(_window, GLFW_KEY_Q)) {
        _camera.MoveCamera(Camera::MoveDirection::Up, moveAmount);
    }
    if (glfwGetKey(_window, GLFW_KEY_E)) {
        _camera.MoveCamera(Camera::MoveDirection::Down, moveAmount);
    }

    double xpos, ypos;
    glfwGetCursorPos(_window, &xpos, &ypos);

    mousePositionCallback(xpos, ypos);
}

void Application::mousePositionCallback(double xpos, double ypos) {
    if (!_firstMouse) {
        _lastMousePosition.x = static_cast<float>(xpos);
        _lastMousePosition.y = static_cast<float>(ypos);
        _firstMouse = true;
    }

    glm::vec2 moveAmount {
            xpos - _lastMousePosition.x,
            _lastMousePosition.y - ypos,
    };

    _lastMousePosition.x = xpos;
    _lastMousePosition.y = ypos;

    _camera.RotateBy(moveAmount.x * _cameraLookSpeed.x, moveAmount.y * _cameraLookSpeed.y);
}

// incrementing camera movement speed
void Application::IncrementSpeed(double amount) {
    _moveSpeed += amount;
}

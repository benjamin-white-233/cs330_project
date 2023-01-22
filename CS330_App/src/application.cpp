#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

Application::Application(std::string WindowTitle, int width, int height) : _applicationName{ WindowTitle }, _width{ width }, _height{ height } {}

void Application::Run() {
    // Open the window
    if (!openWindow()) {
        return;
    }

    _running = true;

    // Set up the scene
    setupScene();

    // Run application
    while (_running) {
        if (glfwWindowShouldClose(_window)) {
            _running = false;
            break;
        }
        // Update
        update();
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
    });

    // if GLAD cannot be loaded, return false
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    // otherwise, return true
    return true;
}


void Application::setupScene() {
    _meshes.emplace_back(Shapes::pyramidVertices, Shapes::pyramidElements);

    // declaring paths to shaderfiles
    Path shaderPath = std::filesystem::current_path() / "shaders";
    _shader = Shader( shaderPath / "basic_shader.vert" , shaderPath / "basic_shader.frag");

}

bool Application::update() {
    return false;
}

bool Application::draw() {
    // background color
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set model view projection matrix
    glm::mat4 view = glm::lookAt(glm::vec3(1.f, 0.5f, -2.f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    glm::mat4 projection = glm::perspective(glm::radians(75.f), (float)_width / (float)_height, 0.1f, 100.f);
    glm::mat4 model = glm::mat4 { 1.f };

    // set matrices in the shader
    _shader.Bind();
    _shader.SetMat4("projection", projection);
    _shader.SetMat4("view", view);
    _shader.SetMat4("model", model);

    // draw each mesh
    for (auto& mesh : _meshes) {
        mesh.Draw();
    }

    glfwSwapBuffers(_window);
    glfwPollEvents();

    return false;
}


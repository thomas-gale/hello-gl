#include <cmath>
#include <iostream>

#include "glad/glad.h"

#include "GLFW/glfw3.h"

#include "Shader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    // Init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window
    int width = 800;
    int height = 600;
    GLFWwindow* window = glfwCreateWindow(width, height, "HelloGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Number of vertex attributes supported
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes
              << std::endl;

    // Viewport
    glViewport(0, 0, width, height);

    // Resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Configure shader
    Shader ourShader("vert.glsl", "frag.glsl");

    // --- Put it all together---

    // Geom
    float vertices[] = {
        // Position, colors
        0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, // top right
        0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        -0.5f, 0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    // 0. Gen all the handles.
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // 1. Bind Vertex Array object
    glBindVertexArray(VAO);

    // 2. Copy vertices array into a vertex buffer for OpenGL to use.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. Copy our index array into an element buffer for OpenGL to use.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);

    // 4a. Link vertex attribute position pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void*)0);
    glEnableVertexAttribArray(0);

    // 4b. Link vertex attribute color pointers
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Rendering...
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Enabled shader
        ourShader.use();

        // Move X over time
        float timeValue = glfwGetTime();
        ourShader.setFloat("movX", std::sin(timeValue)/2.0f);

        // Draw stuff.
        glBindVertexArray(VAO);
        glPolygonMode(GL_FRONT_AND_BACK,
                      GL_FILL); // Draw lines. GL_LINE / GL_FILL
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Swap buffers and check events.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and quit
    glfwTerminate();
    return 0;
}
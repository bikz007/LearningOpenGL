#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

void error_callback(int error, const char* msg) {
    std::string s;
    s = " [" + std::to_string(error) + "] " + msg + '\n';
    std::cerr << s << std::endl;
}

int main()
{
    glfwSetErrorCallback(error_callback);

    // Initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGL we are using
    // In this case we are using version 3.3.8
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Enabling debug context
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    // Tell GLFW we are using the CORE profile
    // So that means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Create a new window
    GLFWwindow* window = glfwCreateWindow(800, 800, "LeaningOpenGL", NULL, NULL);
    // Check for errors
    if (window == NULL)
    {
        error_callback(-1, "Failed to create window!");
        glfwTerminate();
        return -1;
    }
    // Introduce the window into the current context
    // Context is object that holds the whole of OpenGL window
    glfwMakeContextCurrent(window);
    // Load GLAD
    // ask glad to load immediate config for OpenGL
    gladLoadGL();

    // Tell OpenGL viewport of our window
    // In this case it goes from x = 0, y = 0, x = 800, y = 800
    glViewport(0, 0, 800, 800);

    // Specify the color of the background
    // rgba
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // Clean the back buffer and assign new color to it
    glClear(GL_COLOR_BUFFER_BIT);
    // Swap the back buffer with front buffer
    glfwSwapBuffers(window);
    // Main while loop
    while (!glfwWindowShouldClose(window))
    {
        // Take care of all GLFW events
        // Process all window related events
        // such as window appearing
        // window resized
        glfwPollEvents();
    }

    // Delete the window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();

    return 0;
}
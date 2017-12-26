#include "window.h"


Window::Window()
{
    
}


int Window::renderWindow()
{
    //---------
    // GLFW initialization
    //---------
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, false);
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Looker", nullptr, nullptr);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();
    }

    //---------
    // Cleaning
    //---------
    glfwTerminate();

    return 0;
}

#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <iostream>
#include <fstream>

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw_vulkan.h>


class Window
{
    public:
        Window();

        int renderWindow();

    private:
        bool firstMouse = true;

        int windowWidth = 1280;
        int windowHeight = 720;

        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        float lastPosX = windowWidth / 2.0f;
        float lastPosY = windowHeight / 2.0f;

        GLFWwindow* window;
};


#endif // WINDOW_H

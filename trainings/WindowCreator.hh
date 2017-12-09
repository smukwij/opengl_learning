#pragma once

#include <GLFW/glfw3.h>

class WindowCreator
{
    public:
        GLFWwindow* create(const uint32_t width, const uint32_t height);
};

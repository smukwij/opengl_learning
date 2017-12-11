#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderingLoop
{
    public:
        void run(GLFWwindow* window, uint32_t program_id, uint32_t vao);

};




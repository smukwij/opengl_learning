#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "VaoWithVbo.hh"
#include "Program.hh"

class RenderingLoop
{
    public:
        void run(GLFWwindow* window, std::vector<ProgramUPtr>& programs, std::vector<VaoWithVboUPtr>& vaos);

};




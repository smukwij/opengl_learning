#pragma once

#include <vector>
#include <memory>

class OpenGLObject;
struct GLFWwindow;


class RenderingLoop
{
    public:
        void run(GLFWwindow* window
                , std::vector<std::unique_ptr<OpenGLObject>>& objects);
};




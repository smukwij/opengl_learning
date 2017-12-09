#include "FrameBufferHandler.hh"


namespace FrameBufferHandler
{

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

}

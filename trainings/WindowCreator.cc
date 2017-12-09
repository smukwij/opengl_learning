#include "WindowCreator.hh"

GLFWwindow* WindowCreator::create(const uint32_t width, const uint32_t height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    return glfwCreateWindow(width, height, "Learn Opengl", NULL, NULL);

}

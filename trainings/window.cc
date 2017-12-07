#include "window.hh"

GLFWwindow* Window::create()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    constexpr uint32_t width = 800;
    constexpr uint32_t height = 600;
    return glfwCreateWindow(width, height, "Learn Opengl", NULL, NULL);

}

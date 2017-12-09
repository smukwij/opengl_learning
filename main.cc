#include <iostream>

#include <glad/glad.h>
#include "trainings/WindowCreator.hh"
#include "trainings/FrameBufferHandler.hh"
#include "trainings/RenderingLoop.hh"
#include "trainings/ShaderLoader.hh"

int main()
{
    constexpr uint32_t width = 800;
    constexpr uint32_t height = 600;
 
    WindowCreator w_creator;
    GLFWwindow* window(w_creator.create(width, height));

    if(nullptr == window)
    {
        std::cerr << "Ups, something goes wrong!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Cannot initialize GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    }
     
    constexpr uint32_t left_bottom_x = 0;
    constexpr uint32_t left_bottom_y = 0;
    glViewport(left_bottom_x, left_bottom_y, width, height);

    glfwSetFramebufferSizeCallback(window, FrameBufferHandler::framebuffer_size_callback);
   
    ShaderLoader sl;
    std::string vs = sl.load("/home/reczek/opengl_learning/trainings/shaders/triangle.vs");
    uint32_t vertex_shader_id = 0;
    vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    const char* pvs = vs.c_str();
    glShaderSource(vertex_shader_id, 1, &pvs, nullptr);
    glCompileShader(vertex_shader_id);

    int32_t status = 0;
    char info_log[512];
    glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &status);
    if(0 == status)
    {
        glGetShaderInfoLog(vertex_shader_id, 512, nullptr, info_log);
        std::cout << "Shader compilation error: " << info_log << std::endl;
    }



    float vertices [] = {-0.5f, -0.5f, 0.0f,
                         0.5f, -0.5f, 0.0f,
                         0.0f, 0.5f, 0.0f};
    uint32_t vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);



    RenderingLoop rl;
    rl.run( window );

    glfwTerminate();
    return 0;
}

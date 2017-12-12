#include <iostream>
#include <array>

#include <glad/glad.h>
#include "trainings/WindowCreator.hh"
#include "trainings/FrameBufferHandler.hh"
#include "trainings/RenderingLoop.hh"
#include "trainings/Shader.hh"
#include "trainings/Program.hh"
#include "trainings/Vao.hh"
#include "trainings/Vbo.hh"

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

    Shader vs;
    vs.create("triangle.vs", GL_VERTEX_SHADER);
    Shader fs;
    fs.create("triangle.fs", GL_FRAGMENT_SHADER);
   
    Program pr;
    pr.add_shader_id(vs.get_id());
    pr.add_shader_id(fs.get_id());
    pr.create();

    vs.destroy();
    fs.destroy();
    
    float vertices [] = {-0.5f, -0.5f, 0.0f,
                                    0.5f, -0.5f, 0.0f,
                                    0.0f, 0.5f, 0.0f};
    Vao vao;
    vao.create();
    vao.bind();

    Vbo vbo;
    vbo.create();
    vbo.bind();
    vbo.buffer_data(vertices, sizeof(vertices));
    vbo.un_bind();

    vao.un_bind();

    RenderingLoop rl;
    rl.run( window, pr.get_id(), vao.get_id() );

    glfwTerminate();
    return 0;
}

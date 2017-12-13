#include <iostream>
#include <array>

#include <glad/glad.h>
#include "trainings/WindowCreator.hh"
#include "trainings/FrameBufferHandler.hh"
#include "trainings/RenderingLoop.hh"
#include "trainings/Shader.hh"
#include "trainings/Program.hh"
#include "trainings/VaoWithVbo.hh"
#include "trainings/Ebo.hh"


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

    Shader vs2;
    Shader fs2;
    vs2.create("triangle.vs", GL_VERTEX_SHADER);
    fs2.create("triangle_yellow.fs", GL_FRAGMENT_SHADER);

    std::vector<ProgramUPtr> programs;
    programs.push_back(create_program(vs.get_id(), fs.get_id()));
    programs.push_back(create_program(vs2.get_id(), fs2.get_id()));

    vs.destroy();
    fs.destroy();

    vs2.destroy();
    fs2.destroy();

    float first_triangle [] = {-1.0f, 0.0f, 0.0f, 
                               -0.5f, 0.5f, 0.0f,
                                0.0f, 0.0f, 0.0f,
                              };

    float second_triangle [] = { 0.0f, 0.0f, 0.0f,
                                 0.5f, 0.5f, 0.0f,
                                 1.0f, 0.0f, 0.0f
                               };
    {

        std::vector<VaoWithVboUPtr> vaos;
        vaos.push_back(create_vao_with_vbo(first_triangle, sizeof(first_triangle)));
        vaos.push_back(create_vao_with_vbo(second_triangle, sizeof(second_triangle)));
        RenderingLoop rl;
        rl.run( window, programs, vaos );
    }

    glfwTerminate();
    return 0;
}

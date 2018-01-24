#include <iostream>
#include <array>

#include <glad/glad.h>
#include "trainings/FirstObject.hh"
#include "trainings/SecondObject.hh"
#include "trainings/WindowCreator.hh"
#include "trainings/utils/FrameBufferHandler.hh"
#include "trainings/RenderingLoop.hh"


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

    glfwSwapInterval(1);

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

    std::vector<std::unique_ptr<OpenGLObject>> _objects;
    _objects.push_back(create_and_init<FirstObject>()); 
//    _objects.push_back(create_and_init<SecondObject>());
    
    RenderingLoop rl;
    rl.run( window, _objects );
  
    glfwTerminate();
    return 0;
}

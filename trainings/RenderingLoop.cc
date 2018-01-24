#include "RenderingLoop.hh"
#include "OpenGLObject.hh"

#include <GLFW/glfw3.h>

#include <iostream>

namespace 
{
    void process_input(GLFWwindow* window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
        {
            glfwSetWindowShouldClose(window, true);
        }
    }
}

void RenderingLoop::run(GLFWwindow* window
    , std::vector<std::unique_ptr<OpenGLObject>>& objects)
{
    float start_time = glfwGetTime();
    uint32_t counter = 0;
    while(false == glfwWindowShouldClose(window))
    {
        ++counter;
        process_input(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(const auto& o : objects)
        {
            o->process_key(window);
            o->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    float stop_time = glfwGetTime();;
    std::cout << "Time: " << ( stop_time - start_time)/static_cast<float>(counter) << std::endl;
}


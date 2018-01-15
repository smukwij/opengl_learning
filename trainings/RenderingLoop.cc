#include "RenderingLoop.hh"
#include "OpenGLObject.hh"

#include <GLFW/glfw3.h>



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
    while(false == glfwWindowShouldClose(window))
    {
        process_input(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(const auto& o : objects)
        {
            o->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


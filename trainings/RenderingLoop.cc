#include "RenderingLoop.hh"

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



void RenderingLoop::run(GLFWwindow* window)
{
    while(false == glfwWindowShouldClose(window))
    {
        process_input(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


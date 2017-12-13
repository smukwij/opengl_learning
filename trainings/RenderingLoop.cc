#include "RenderingLoop.hh"
//#include <glad/glad.h>

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



void RenderingLoop::run(GLFWwindow* window, std::vector<ProgramUPtr>& programs, std::vector<VaoWithVboUPtr>& vaos)
{
    while(false == glfwWindowShouldClose(window))
    {
        process_input(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for(uint32_t u = 0; u < vaos.size(); ++u) 
        {
            programs.at(u)->use();
            vaos.at(u)->bind_vao();

            glDrawArrays(GL_TRIANGLES, 0, 3);
            vaos.at(u)->unbind_vao();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


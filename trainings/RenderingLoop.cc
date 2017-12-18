#include "RenderingLoop.hh"
#include "Uniform.hh"

#include <iostream>
#include <cmath>

namespace 
{
    void process_input(GLFWwindow* window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
        {
            glfwSetWindowShouldClose(window, true);
        }
    }

    float get_green_value()
    {
        return std::sin(glfwGetTime());
    }

    float get_x_value()
    {
        return (std::sin(glfwGetTime())/2.0f)+0.5f;
    }
}



void RenderingLoop::run(GLFWwindow* window, std::vector<ProgramUPtr>& programs, std::vector<VaoWithVboUPtr>& vaos, Texture& tex)
{
    Uniform uniform;
    for(const auto& pr : programs) 
    {
        if(true == pr->is_uniform())
        {
            uniform.init(pr->get_id(), "offset");
        }
    }

    while(false == glfwWindowShouldClose(window))
    {
        process_input(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for(uint32_t u = 0; u < vaos.size(); ++u) 
        {
            programs.at(u)->use();
            if(true == programs.at(u)->is_uniform())
            {
                uniform.set_value(get_x_value());
            }

            tex.bind();
            vaos.at(u)->bind_vao();

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            vaos.at(u)->unbind_vao();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


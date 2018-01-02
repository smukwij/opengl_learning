#include "RenderingLoop.hh"
#include "Uniform.hh"

#include <iostream>
#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


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

    const float* get_trans_matrix(glm::mat4& trans)
    {
        trans = glm::rotate(trans, static_cast<float>(glfwGetTime()), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));

        return glm::value_ptr(trans);
    }
}



void RenderingLoop::run(GLFWwindow* window
        , std::vector<ProgramUPtr>& programs
        , std::vector<VaoWithVboUPtr>& vaos
        , std::vector<TextureUPtr>& tex)
{
    Uniform uniform;
    for(const auto& pr : programs) 
    {
        if(true == pr->is_uniform())
        {
            uniform.init(pr->get_id(), "transform");
        }
    }
    while(false == glfwWindowShouldClose(window))
    {
        process_input(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 trans;

        for(uint32_t u = 0; u < vaos.size(); ++u) 
        {
            programs.at(u)->use();
            if(true == programs.at(u)->is_uniform())
            {
                uniform.set_value(get_trans_matrix(trans));
            }

            for(uint32_t t = 0; t < tex.size(); ++t)
            {
                tex.at(t)->activate(t);
                tex.at(t)->bind();
            }
            vaos.at(u)->bind_vao();

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            vaos.at(u)->unbind_vao();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


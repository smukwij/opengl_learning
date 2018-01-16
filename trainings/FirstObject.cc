#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "FirstObject.hh"

#include "utils/Shader.hh"
#include "utils/Program.hh"
#include "utils/Texture.hh"
#include "utils/VaoWithVbo.hh"
#include "utils/Uniform.hh"

#include <GLFW/glfw3.h>

FirstObject::FirstObject()
{
}

FirstObject:: ~FirstObject()
{
}

void FirstObject::setup()
{
    Shader vs;
    vs.create("triangle.vs", GL_VERTEX_SHADER);
    Shader fs;
    fs.create("triangle.fs", GL_FRAGMENT_SHADER);
    _program = create_program(vs.get_id(), fs.get_id());

    vs.destroy();
    fs.destroy();

    TextureUPtr tex = std::make_unique<Texture>();
    tex->create();
    tex->bind();
    tex->load("container.jpg");
    tex->set_params();

    TextureUPtr tex2 = std::make_unique<Texture>();
    tex2->create();
    tex2->bind();
    tex2->load("awesomeface.jpg");

    _textures.push_back(std::move(tex));
    _textures.push_back(std::move(tex2));

    _program->use();
    glUniform1i(glGetUniformLocation(_program->get_id(), "texture1"), 0);
    glUniform1i(glGetUniformLocation(_program->get_id(), "texture2"), 1);

    tex->unbind();
    tex2->unbind();

    glm::mat4 view;
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    constexpr float width = 800.0f;
    constexpr float height = 600.0f;
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), width/height, 0.1f, 100.0f);

     _uniform = std::make_unique<Uniform>();
    _uniform->init(_program->get_id(), "model");

    int view_loc = glGetUniformLocation(_program->get_id(), "view");
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));

    int projection_loc = glGetUniformLocation(_program->get_id(), "projection");
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));


    float ver[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    _vaos = create_vao_with_vbo(ver, sizeof(ver));

    glEnable(GL_DEPTH_TEST);
}

namespace 
{
    float get_green_value()
    {
        return std::sin(glfwGetTime());
    }

    float get_x_value()
    {
        return (std::sin(glfwGetTime())/2.0f)+0.5f;
    }
    const float* get_model_matrix(glm::mat4& model, uint32_t counter)
    {
        glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f), 
            glm::vec3( 2.0f,  5.0f, -15.0f), 
            glm::vec3(-1.5f, -2.2f, -2.5f),  
            glm::vec3(-3.8f, -2.0f, -12.3f),  
            glm::vec3( 2.4f, -0.4f, -3.5f),  
            glm::vec3(-1.7f,  3.0f, -7.5f),  
            glm::vec3( 1.3f, -2.0f, -2.5f),  
            glm::vec3( 1.5f,  2.0f, -2.5f), 
            glm::vec3( 1.5f,  0.2f, -1.5f), 
            glm::vec3(-1.3f,  1.0f, -1.5f)  
        };
        model = glm::translate(model, cubePositions[counter]);
 
        if(0 != (counter % 3))
        {
            return glm::value_ptr(model);
        }

       float angle = (static_cast<float>(counter) + 0.1f)* static_cast<float>(glfwGetTime())*glm::radians(50.0f);
        float y = static_cast<float>(counter)/10.0f;
        float x = 1.0f - y;
        float z = std::sin(static_cast<float>(glfwGetTime()));
        model = glm::rotate(model, angle, glm::vec3(x, y, z));
        return glm::value_ptr(model);
    }


    const float* get_trans_matrix(glm::mat4& trans)
    {
    //    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    //    trans = glm::rotate(trans, static_cast<float>(glfwGetTime()), glm::vec3(0.0, 0.0, 1.0));
        return glm::value_ptr(trans);
    }
}

void FirstObject::draw()
{
    _program->use();
    for(uint32_t t = 0; t < _textures.size(); ++t)
    {
        _textures.at(t)->activate(t);
        _textures.at(t)->bind();
    }
    _vaos->bind_vao();

    for( uint32_t u = 0; u < 10; ++u)
    {
        glm::mat4 model;
        _uniform->set_value(get_model_matrix(model, u));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    _vaos->unbind_vao();
}


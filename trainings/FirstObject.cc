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
    _program->use_uniform();

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
    _uniform = std::make_unique<Uniform>();
    _uniform->init(_program->get_id(), "transform");
    
    tex->unbind();
    tex2->unbind();


    float ver [] = { 0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
                     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
                    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
                    -0.5f, 0.5f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    uint32_t ind [] = {0, 1, 3,
                       1, 2, 3 
    };

    _vaos = create_vao_with_vbo(ver, sizeof(ver), ind, sizeof(ind));
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

    const float* get_trans_matrix(glm::mat4& trans)
    {
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, static_cast<float>(glfwGetTime()), glm::vec3(0.0, 0.0, 1.0));
        return glm::value_ptr(trans);
    }
}

void FirstObject::draw()
{
        glm::mat4 trans;

        _program->use();
        _uniform->set_value(get_trans_matrix(trans));

        for(uint32_t t = 0; t < _textures.size(); ++t)
        {
            _textures.at(t)->activate(t);
            _textures.at(t)->bind();
        }
        _vaos->bind_vao();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        _vaos->unbind_vao();
}


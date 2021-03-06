#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SecondObject.hh"

#include "utils/Shader.hh"
#include "utils/Program.hh"
#include "utils/Texture.hh"
#include "utils/VaoWithVbo.hh"
#include "utils/Uniform.hh"

#include <GLFW/glfw3.h>

SecondObject::SecondObject()
{
}

SecondObject::~SecondObject()
{
}

void SecondObject::setup()
{
    Shader vs;
    vs.create("triangle.vs", GL_VERTEX_SHADER);
    Shader fs;
    fs.create("triangle.fs", GL_FRAGMENT_SHADER);
    _program = create_program(vs.get_id(), fs.get_id());
//    _program->use_uniform();

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
    const float* get_trans_matrix(glm::mat4& trans)
    {
        trans = glm::translate(trans, glm::vec3(-0.5f, 0.5f, 0.0f));
        float time = glfwGetTime();
        float x_scale = std::sin(time);
        float y_scale = std::cos(time);
        float z_scale = 1;
        trans = glm::scale(trans, glm::vec3(x_scale, y_scale, z_scale));
        return glm::value_ptr(trans);
    }
}


void SecondObject::draw()
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


#include "FirstObject.hh"


FristObject::FirstObject()
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
    ProgramUPtr program = create_program(vs.get_id(), fs.get_id());
    program->use_uniform();

    std::vector<ProgramUPtr> programs;
    programs.push_back(std::move(program));

    vs.destroy();
    fs.destroy();

    float ver [] = { 0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
                     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
                    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
                    -0.5f, 0.5f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    uint32_t ind [] = {0, 1, 3,
                       1, 2, 3 
    };

    TextureUPtr tex = std::make_unique<Texture>();
    tex->create();
    tex->bind();
    tex->load("container.jpg");
    tex->set_params();

    TextureUPtr tex2 = std::make_unique<Texture>();
    tex2->create();
    tex2->bind();
    tex2->load("awesomeface.jpg");

    std::vector<TextureUPtr> textures;
    textures.push_back(std::move(tex));
    textures.push_back(std::move(tex2));

    programs.at(0)->use();
    glUniform1i(glGetUniformLocation(programs.at(0)->get_id(), "texture1"), 0);
    glUniform1i(glGetUniformLocation(programs.at(0)->get_id(), "texture2"), 1);
     
    tex->unbind();
    tex2->unbind();

    std::vector<VaoWithVboUPtr> vaos;
    vaos.push_back(create_vao_with_vbo(ver, sizeof(ver), ind, sizeof(ind)));

}

void FirstObject::draw()
{
}


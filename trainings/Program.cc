#include "Program.hh"

#include <glad/glad.h>
#include <iostream>

namespace {
    void check_and_print_log(const uint32_t id)
    {
        char info_log[512];
        int32_t status = 0;
        glGetProgramiv(id, GL_LINK_STATUS, &status);
        if(0 == status)
        {
            glGetProgramInfoLog(id, 512, nullptr, info_log);
            std::cout << "Linking errog: "<< info_log << std::endl;
        }
    }

}

Program::Program()
    : _id(0)
{
}


void Program::add_shader_id(const uint32_t id)
{
    _shader_ids.push_back(id);
}


void Program::create()
{
    _id = glCreateProgram();

    for(const auto& id : _shader_ids)
    {
        glAttachShader(_id, id);
    }
    glLinkProgram(_id);
    check_and_print_log(_id);
}

void Program::use() const
{
    glUseProgram(_id);
}

uint32_t Program::get_id() const
{
    return _id;
}

#include "Uniform.hh"

#include <glad/glad.h>

#include <iostream>

Uniform::Uniform()
    : _location(-1)
{
}

Uniform::~Uniform() = default;

void Uniform::init(uint32_t program_id, const std::string& name)
{
    _location = glGetUniformLocation(program_id, name.c_str());
}
 
void Uniform::set_value(const float* value) const
{
    if( -1 != _location)
    {
        glUniformMatrix4fv(_location, 1, GL_FALSE, value );
    }
    else
    {
        std::cerr << "Cannot find uniform" << std::endl;
    }
}

#include "Uniform.hh"

#include <glad/glad.h>


Uniform::Uniform()
    : _location(-1)
{
}

Uniform::~Uniform() = default;

void Uniform::init(uint32_t program_id, const std::string& name)
{
    _location = glGetUniformLocation(program_id, name.c_str());
}
 
void Uniform::set_value(float value) const
{
    if( -1 != _location)
    {
        glUniform2f(_location, value, 0.0f);
    }
}

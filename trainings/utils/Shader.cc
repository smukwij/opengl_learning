#include "Shader.hh"
#include "ShaderLoader.hh"

#include <iostream>
#include <GLFW/glfw3.h>

Shader::Shader()
    : _id(0)
{
}

Shader::~Shader()
{
    destroy();
}

void Shader::create(const std::string& file_name, const GLenum shader_type)
{
    ShaderLoader sl;
    std::string s = sl.load(file_name);
    _id = glCreateShader(shader_type);
    const char* ps = s.c_str();
    glShaderSource(_id, 1, &ps, nullptr);
    glCompileShader(_id);

    int32_t status = 0;
    char info_log[512];
    glGetShaderiv(_id, GL_COMPILE_STATUS, &status);
    if(0 == status)
    {
        glGetShaderInfoLog(_id, 512, nullptr, info_log);
        std::cout << "Shader compilation error: " << info_log << std::endl;
    }
}


void Shader::destroy()
{
    glDeleteShader(_id);
}

uint32_t Shader::get_id() const
{
    return _id;
}

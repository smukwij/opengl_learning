#include "Vao.hh"

#include <glad/glad.h>

Vao::Vao()
  :  _id(0)
{
}

Vao::~Vao() = default;

void Vao::create()
{
    glGenVertexArrays(1, &_id);
}

void Vao::bind() const
{
    glBindVertexArray(_id);
}

void Vao::unbind() const
{
    glBindVertexArray(0);
}

void Vao::destroy()
{
    glDeleteVertexArrays(1, &_id);
}

uint32_t Vao::get_id() const
{
    return _id;
}

#include "Ebo.hh"

#include <glad/glad.h>

Ebo::Ebo()
  :  _id(0)
{
}


Ebo::~Ebo() = default;

void Ebo::create()
{
    glGenBuffers(1, &_id);
}

void Ebo::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
}

void Ebo::unbind()
{
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Ebo::buffer_data(uint32_t* data, size_t size)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Ebo::destroy()
{
    glDeleteBuffers(1, &_id);
}


uint32_t Ebo::get_id() const
{
    return _id;
}

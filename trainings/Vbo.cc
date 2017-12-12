#include "Vbo.hh"
#include <iostream>

#include <glad/glad.h>

Vbo::Vbo()
  :  _id(0)
{
}


Vbo::~Vbo() = default;

void Vbo::create()
{
    glGenBuffers(1, &_id);
}

void Vbo::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void Vbo::un_bind()
{
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vbo::buffer_data(float* data, size_t size)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Vbo::enable_vertex()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Vbo::destroy()
{
    glDeleteBuffers(1, &_id);
}

uint32_t Vbo::get_id() const
{
    return _id;
}
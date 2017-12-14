#include "VaoWithVbo.hh"

VaoWithVbo::VaoWithVbo() = default;

VaoWithVbo::~VaoWithVbo()
{
    _vao.destroy();
    _vbo.destroy();
}

void VaoWithVbo::create(float* data, size_t size)
{
    _vao.create();
    _vao.bind();

    _vbo.create();
    _vbo.bind();
    _vbo.buffer_data(data, size);

    _vbo.enable_vertex();
    _vbo.un_bind();

    _vao.un_bind();
}

void VaoWithVbo::bind_vao() const
{
    _vao.bind();
}

void VaoWithVbo::unbind_vao() const
{
    _vao.un_bind();
}

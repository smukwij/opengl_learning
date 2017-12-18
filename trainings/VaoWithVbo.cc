#include "VaoWithVbo.hh"

VaoWithVbo::VaoWithVbo() = default;

VaoWithVbo::~VaoWithVbo()
{
    _vao.destroy();
    _vbo.destroy();
}

void VaoWithVbo::create(float* data, size_t size, uint32_t* ebo_data, size_t ebo_size)
{
    _vao.create();
    _vao.bind();

    _vbo.create();
    _vbo.bind();
    _vbo.buffer_data(data, size);

    _vbo.enable_vertex();
    _vbo.unbind();

    if(nullptr !=  ebo_data)
    {
        _ebo.create();
        _ebo.bind();
        _ebo.buffer_data(ebo_data, ebo_size);
    }

    _vao.unbind();

    if(nullptr != ebo_data)
    {
        _ebo.unbind();
    }
}

void VaoWithVbo::bind_vao() const
{
    _vao.bind();
}

void VaoWithVbo::unbind_vao() const
{
    _vao.unbind();
}

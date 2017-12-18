#pragma once

#include "Vao.hh"
#include "Vbo.hh"
#include "Ebo.hh"

#include <iostream>
#include <memory>


class VaoWithVbo
{
    public: 
        VaoWithVbo();
        ~VaoWithVbo();

        void create(float* data, size_t size, uint32_t* ebo_data, size_t ebo_size);
        void bind_vao() const;
        void unbind_vao() const;

    private:
        Vao _vao;
        Vbo _vbo;
        Ebo _ebo;
};

using VaoWithVboUPtr = std::unique_ptr<VaoWithVbo>;

inline VaoWithVboUPtr create_vao_with_vbo(float* data, size_t size)
{
    std::unique_ptr<VaoWithVbo> vao_with_vbo(new VaoWithVbo());
    vao_with_vbo->create(data, size, nullptr, 0);
    return vao_with_vbo;
}


inline VaoWithVboUPtr create_vao_with_vbo(float* data, size_t size, uint32_t* ebo_data, size_t ebo_size)
{
    std::unique_ptr<VaoWithVbo> vao_with_vbo(new VaoWithVbo());
    vao_with_vbo->create(data, size, ebo_data, ebo_size);
    return vao_with_vbo;
}



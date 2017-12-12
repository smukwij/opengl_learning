#pragma once

#include <cstdint>
#include <glad/glad.h>


class Vbo
{
    public:
        Vbo();
        ~Vbo();
        void create();
        void bind();
        void un_bind();
        
        void buffer_data(float* data, size_t size);
        void enable_vertex();
        void destroy();


        uint32_t get_id() const;

    private:
        uint32_t _id;
};

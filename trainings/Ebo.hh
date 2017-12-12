#pragma once

#include <cstdint>
#include <glad/glad.h>


class Ebo
{
    public:
        Ebo();
        ~Ebo();
        void create();
        void bind();
        void un_bind();
        
        void buffer_data(uint32_t* data, size_t size);
        void destroy();

        uint32_t get_id() const;

    private:
        uint32_t _id;
};

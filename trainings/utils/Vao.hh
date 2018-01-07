#pragma once

#include <cstdint>

class Vao
{
    public:
        Vao();
        ~Vao();
        void create();
        void bind() const;
        void unbind() const;
        void destroy(); 

        uint32_t get_id() const;

    private:
        uint32_t _id;
};

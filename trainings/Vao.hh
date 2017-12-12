#pragma once

#include <cstdint>

class Vao
{
    public:
        Vao();
        ~Vao();
        void create();
        void bind();
        void un_bind();
        void destroy(); 

        uint32_t get_id() const;

    private:
        uint32_t _id;
};

#pragma once

#include <cstdint>
#include <string>

class Image;


class Texture 
{
    public:
        Texture();
        ~Texture();
        void create();
        void bind() const;
        void load(const std::string& file);
        void set_params() const;
        void unbind() const;
        void destroy(); 

    private:
        uint32_t _id;
};


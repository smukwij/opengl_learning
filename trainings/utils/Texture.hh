#pragma once

#include <cstdint>
#include <string>
#include <memory>

class Image;


class Texture 
{
    public:
        Texture();
        ~Texture();
        void create();
        void activate(const uint32_t texture_unit);
        void bind() const;
        void load(const std::string& file);
        void set_params() const;
        void unbind() const;
        void destroy(); 

    private:
        uint32_t _id;
};

using TextureUPtr = std::unique_ptr<Texture>;



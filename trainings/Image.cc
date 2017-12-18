#include "Image.hh"

#include <stb_image/stb_image.h>

#include <iostream>

Image::Image()
    : _data( nullptr )
    , _height( 0x0 )
    , _width ( 0x0 )
    , _nr_channels( 0x0 )
{
}

Image::~Image()
{
    stbi_image_free(_data);
}

namespace {

    std::string get_path()
    {
        return "/home/reczek/opengl_learning/res/textures/";
    }
}


void Image::load(const std::string& file)
{
    std::string tmp = get_path() + file;
    _data = stbi_load(tmp.c_str(), &_width, &_height, &_nr_channels, 0);

    if( nullptr == _data) 
    {
        std::cout << "Image: Cannot load image! Path: " << tmp << std::endl;
    }
    else
    {
        std::cout << "Image: " << tmp << " loaded" << std::endl;
    }
}

uint8_t* Image::data()
{
    return _data;
}

int32_t Image::width() const
{
    return _width;
}

int32_t Image::height() const
{
    return _height;
}


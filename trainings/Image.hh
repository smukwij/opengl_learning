#pragma once

#include <cstdint>
#include <string>

class Image
{
    public:
        Image();
        ~Image();

        void load( const std::string& file);
        uint8_t* data();
        int32_t height() const;
        int32_t width() const;


    private:
        uint8_t* _data;
        int32_t _height;
        int32_t _width;
        int32_t _nr_channels;
};



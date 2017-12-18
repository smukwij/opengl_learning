#include "Texture.hh"
#include "Image.hh"

#include <glad/glad.h>



Texture::Texture()
    : _id( 0x0 )
{
}

Texture::~Texture()
{
}

void Texture::create()
{
    glGenTextures(1, &_id);
}

void Texture::load(const std::string& file)
{
    Image image;
    image.load(file);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.data());
    glGenerateMipmap(GL_TEXTURE_2D); 
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, _id);
}

void Texture::set_params() const
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::destroy()
{
}

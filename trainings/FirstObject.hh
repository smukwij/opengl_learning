#pragma once
#include <memory>
#include <vector>


#include "OpenGLObject.hh"

class Program;
class Texture;
class VaoWithVbo;
class Uniform;


class FirstObject final: public OpenGLObject
{
public:
    FirstObject();
    virtual ~FirstObject();

    void setup() override;
    void draw() override;

private:
    std::unique_ptr<Program>                _program;
    std::vector<std::unique_ptr<Texture>>   _textures;
    std::unique_ptr<VaoWithVbo>             _vaos;
    std::unique_ptr<Uniform>                _uniform;
};

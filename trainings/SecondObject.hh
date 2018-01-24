#pragma once

#include "OpenGLObject.hh"
#include <memory>
#include <vector>

class Program;
class Texture;
class VaoWithVbo;
class Uniform;

class SecondObject final : public OpenGLObject
{
public:
    SecondObject();
    virtual ~SecondObject();

    void setup() override;
    void draw() override;
    void process_key(GLFWwindow* window) override
    {
    }

private:
    std::unique_ptr<Program>                _program;
    std::vector<std::unique_ptr<Texture>>   _textures;
    std::unique_ptr<VaoWithVbo>             _vaos;
    std::unique_ptr<Uniform>                _uniform;
};




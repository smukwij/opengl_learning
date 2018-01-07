#pragma once

#include <memory>

class OpenGLObject
{
public:
    OpenGLObject() = default;
    virtual ~OpenGLObject() = default;

    virtual void setup() = 0;
    virtual void draw() = 0;
};


template<class Object>
std::unique_ptr<Object> create_and_init()
{
    std::unique_ptr<Object> object = std::make_unique<Object>();
    object->setup();
    return object;
}



#pragma once


class OpenGLObject
{
public:
    OpenGLObject() = default;
    virtual ~OpenGLObject() = default;

    virtual void setup() = 0;
    virtual void draw() = 0;


};




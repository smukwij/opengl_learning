#pragma once

#include "OpenGLObject.hh"


class FirstObject : public OpenGLObject
{
public:
    FirstObject();
    virtual ~FirstObject();

    void setup() = override;
    void draw() = override;


};

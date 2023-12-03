#pragma once
#include "./Zbuffer.h"

class Painter
{
public:
    Painter(/* args */);
    void render(Zbuffer* buffer);
    ~Painter();
};


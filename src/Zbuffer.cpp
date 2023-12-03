#include "../include/Zbuffer.h"

Zbuffer::Zbuffer(int width,int height)
{
    this->width=width;
    this->height=height;
    //初始化zbuffer
    for(int i=0;i<width;i++)
        for(int j=0;j<height;j++)
            buffer[i][j]=-__FLT_MAX__;
}
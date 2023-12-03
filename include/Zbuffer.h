#pragma once

#include "../include/Model.h"
#include "../include/OctTree.h"
class Zbuffer
{
public:
    int width,height;    //缓冲区宽高
    Vector3 cameraPosition; //相机位置
    float MVP[4][4];    //MVP矩阵
    float buffer[512][512];
    Zbuffer(int width,int height);
    // ~Zbuffer();
};


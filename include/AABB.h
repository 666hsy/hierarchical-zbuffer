#pragma once

//AABB包围盒
class AABB
{
public:
    float x_min=100, x_max=-100, y_min=100, y_max=-100, z_min=100, z_max=-100;
    AABB(/* args */);
    AABB(float x0,float x1,float y0,float y1,float z0,float z1);    //构造AABB盒子
};

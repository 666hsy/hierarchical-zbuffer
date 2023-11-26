#include "../include/AABB.h"

AABB::AABB()
{
    x_min=100, x_max=-100, y_min=100, y_max=-100, z_min=100, z_max=-100;
}
AABB::AABB(float x0,float x1,float y0,float y1,float z0,float z1)
{
    x_max=x0,x_min=x1,y_max=y0,y_min=y1,z_max=z0,z_min=z1;
}
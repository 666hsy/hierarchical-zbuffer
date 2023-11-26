#include "../include/Model.h"
class Zbuffer
{
public:
    int weight,height;    //缓冲区宽高
    Vector3 cameraPosition; //相机位置
    float MVP[4][4];    //MVP矩阵
    Zbuffer(/* args */);
    ~Zbuffer();
};

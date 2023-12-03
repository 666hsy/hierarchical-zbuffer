#pragma once

#include "./OctTree.h"
#include "./Zbuffer.h"

struct MipMapNode    //buffer结点
{
// public:
    float z;    //z值
    int x_min,x_max,y_min,y_max;  //该结点覆盖的范围
    MipMapNode* child[4]; //子结点
    MipMapNode(int x0,int x1,int y0,int y1)
    {
        x_min=x0,x_max=x1,y_min=y0,y_max=y1;
        z=-__FLT_MAX__; //z值初始化为负无穷
    }
};

class OctreeZbuffer:public Zbuffer
{
public:
    OctTree* octTree;   //组织场景的八叉树
    MipMapNode* root;
    OctreeZbuffer(int weight,int height,OctTree* tree);
    void InitMipMap(int x_min,int x_max,int y_min,int y_max,MipMapNode* root);
    // ~OctreeZbuffer();
};


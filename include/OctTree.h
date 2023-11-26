#pragma once
#include "./Model.h"
#include "./AABB.h"

struct OctTreeNode
{
    AABB *bound=new AABB();
    int faceNums;   //该节点包含的面数
    OctTreeNode* son[8];   //8个子结点
    void init(AABB *bd)
    {
        bound->x_max=bd->x_max;
        bound->x_min=bd->x_min;
        bound->y_max=bd->y_max;
        bound->y_min=bd->y_min;
        bound->z_max=bd->z_max;
        bound->z_min=bd->z_min;
    }
    void print()
    {
        cout<<"x_max:"<<bound->x_max<<endl<<"x_min:"<<bound->x_min<<endl
            <<"y_max:"<<bound->y_max<<endl<<"y_min:"<<bound->y_min<<endl
            <<"z_max:"<<bound->z_max<<endl<<"z_min:"<<bound->z_min<<endl;
    }
};

class OctTree
{
public:
    Model* model;    //场景
    int nodeNums;   //结点个数
    OctTreeNode* root=new OctTreeNode();  //根节点
    OctTree(Model* model);
    void insert(Face face,OctTreeNode* parent);
    bool check(Face face,AABB bound);   //检查包围盒是否包围了该三角面
    ~OctTree();
};


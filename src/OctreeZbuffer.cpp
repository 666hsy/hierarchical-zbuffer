#include "../include/OctreeZbuffer.h"
#include "../include/OctTree.h"
using namespace std;
OctreeZbuffer::OctreeZbuffer(int width,int height,OctTree* tree):Zbuffer(width,height)
{
    this->octTree=tree;
    root=NULL;
    InitMipMap(0,width-1,0,height-1,root);
}
void OctreeZbuffer::InitMipMap(int x_min,int x_max,int y_min,int y_max,MipMapNode* node)
{

    if(x_min>x_max||y_min>y_max) return;
    if(node==NULL) node=new MipMapNode(x_min,x_max,y_min,y_max);
    for(int i=0;i<3;i++) node->child[i]=NULL;
    if(x_min==x_max)    //叶子结点
    {
        return;
    }
    int x_mid=x_min+x_max>>1,y_mid=y_min+y_max>>1;
    //递归构造四个儿子
    InitMipMap(x_min,x_mid,y_min,y_mid,node->child[0]);
    InitMipMap(x_min,x_mid,y_mid+1,y_max,node->child[1]);
    InitMipMap(x_mid+1,x_max,y_min,y_mid,node->child[2]);
    InitMipMap(x_mid+1,x_max,y_mid+1,y_max,node->child[3]);
}
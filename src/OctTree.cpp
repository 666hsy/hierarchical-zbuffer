#include "../include/OctTree.h"
#include "../include/AABB.h"
#include "../include/Model.h"
#include<iostream>
using namespace std;
OctTree::OctTree(Model* model)
{
    AABB *bound=new AABB(); //最外围包围盒
    nodeNums=1;
    for(int i=0;i<model->pointsNum;i++)
    {
        bound->x_max=max(bound->x_max,model->points[i].x);
        bound->x_min=min(bound->x_min,model->points[i].x);
        bound->y_max=max(bound->y_max,model->points[i].y);
        bound->y_min=min(bound->y_min,model->points[i].y);
        bound->z_max=max(bound->z_max,model->points[i].z);
        bound->z_min=min(bound->z_min,model->points[i].z);
    }
    root->bound=bound;
    this->model=model;
    for(int i=0;i<model->facesNum;i++)  //将每个面片加到八叉树中
    {
        insert(model->faces[i],root);   
    }
    cout<<"共有"<<nodeNums<<"个结点"<<endl;
}

bool OctTree::check(Face face,AABB bound)   //检查包围盒是否包围了该三角面
{
    //面的三个顶点
    Vector3 v0=model->points[face.pointIndex[0]],v1=model->points[face.pointIndex[1]],v2=model->points[face.pointIndex[2]];
    float x_min=min(v0.x,min(v1.x,v2.x)),x_max=max(v0.x,max(v1.x,v2.x));
    float y_min=min(v0.y,min(v1.y,v2.y)),y_max=max(v0.y,max(v1.y,v2.y));
    float z_min=min(v0.z,min(v1.z,v2.z)),z_max=max(v0.z,max(v1.z,v2.z));
    
    if(x_min>=bound.x_min && x_max<=bound.x_max     //三个顶点完全在包围盒中
    && y_min>=bound.y_min && y_max<=bound.y_max
    && z_min>=bound.z_min && z_max<=bound.z_max)
        return true;
    else
        return false;
}

void OctTree::insert(Face face,OctTreeNode* parent) //将face加到parent为父节点的结点中
{
    parent->faceNums++;
    AABB *bound=parent->bound;
    float boundary[3][3]={
        bound->x_max,(bound->x_max+bound->x_min)/2,bound->x_min,
        bound->y_max,(bound->y_max+bound->y_min)/2,bound->y_min,
        bound->z_max,(bound->z_max+bound->z_min)/2,bound->z_min,
    };
    int cnt=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                AABB *subBound=new AABB(boundary[0][i],boundary[0][i+1],boundary[1][j],boundary[1][j+1],boundary[2][k],boundary[2][k+1]);
                if(check(face, *subBound))
                {
                    if(parent->son[cnt]==nullptr)
                    {
                        parent->son[cnt]=new OctTreeNode();
                        parent->son[cnt]->bound=subBound;
                        nodeNums++;
                    }
                    insert(face,parent->son[cnt]);
                }
                cnt++;
            }
        }
    }
}
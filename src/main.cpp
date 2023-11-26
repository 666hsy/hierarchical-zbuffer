#include <GL/freeglut.h>
#include<iostream>
#include<string>
#include "./Model.cpp"
#include "./OctTree.cpp"
#include "./AABB.cpp"
using namespace std;
int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        cout<<"请输入模型"<<endl;
        return 0;
    }
    glutInit(&argc, argv);
    Model *module =new Model();
    if(module->loadModel(string(argv[1])))
    {
        OctTree* tree = new OctTree(module);    //将场景组织成八叉树
    }
    else
    {
        cout<<"加载错误，请检查模型"<<endl;
        return 0;
    }
}
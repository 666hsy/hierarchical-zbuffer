#pragma once

#include<vector>
#include<string>
using namespace std;

struct Vector3  //顶点
{
    float x,y,z;
};
struct Face
{
    int pointIndex[3];  //存放3个顶点的下标
};

class Model
{
public:
    int pointsNum;  //顶点个数
    int facesNum;   //面的个数
    vector<Vector3> points; //所有顶点
    vector<Face> faces; //所有面
    bool loadModel(string filename);
    ~Model();
};

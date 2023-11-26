#include "../include/Model.h"
#include<fstream>
#include<iostream>
using namespace std;
bool Model::loadModel(string filename)
{
    ifstream file(filename);
    if(!file.is_open())
    {
        return false;
    }

    string type;
    while (file >> type)
    {
        if (type == "v")
        {
            Vector3 v;
            file >> v.x >> v.y >> v.z;
            points.push_back(v);
            pointsNum++;
        }
        else if(type=="f")
        {
            Face face;
            int a[3];
            file>>a[0]>>a[1]>>a[2];
            for(int i=0;i<3;i++)
                face.pointIndex[i]=a[i]-1;
            
            faces.push_back(face);
            facesNum++;
        }
    }
}
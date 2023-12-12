#include "objectpolygon.h"

ObjectPolygon::ObjectPolygon(Shader& shader,const Way& way,QVector3D color,int priority){
    this->priority=priority;
    vector<QVector2D> vertexs;
    for(auto i:way.nodes)vertexs.push_back(QVector2D(i.normalized_lon,i.normalized_lat));
    PolygenRenderer=new staticSpritePolygonRenderer(shader,vertexs,color);
}

ObjectPolygon::~ObjectPolygon(){
    delete PolygenRenderer;
}

void ObjectPolygon::Draw(QVector2D position,QVector2D size){
    PolygenRenderer->Draw(position,size);
}

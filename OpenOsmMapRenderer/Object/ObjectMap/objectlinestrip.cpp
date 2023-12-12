#include "objectlinestrip.h"

ObjectLineStrip::ObjectLineStrip(Shader& shader,const Way& way,QVector3D color,int priority){
    this->priority=priority;
    vector<QVector2D> vertexs;
    for(auto i:way.nodes)vertexs.push_back(QVector2D(i.normalized_lon,i.normalized_lat));
    LineStripRenderer=new staticSpriteLinestripRenderer(shader,vertexs,color);
}

ObjectLineStrip::~ObjectLineStrip(){
    delete LineStripRenderer;
}

void ObjectLineStrip::Draw(QVector2D position,QVector2D size){
    LineStripRenderer->Draw(position,size);
}

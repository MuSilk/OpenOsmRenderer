#ifndef OBJECTPOLYGON_H
#define OBJECTPOLYGON_H

#include "Renderer/staticspritepolygon.h"
#include "Xml/way.h"

class ObjectPolygon
{
public:
    ObjectPolygon(){}
    ObjectPolygon(Shader& shader,const Way& way,QVector3D color=QVector3D(1.0,1.0,1.0),int priority=0);
    ~ObjectPolygon();
    void Draw(QVector2D position,QVector2D size);
    bool operator<(const ObjectPolygon& obj)const{
        return priority<obj.priority;
    }
private:
    staticSpritePolygonRenderer* PolygenRenderer;
    int priority;
};

#endif // OBJECTPOLYGON_H

#ifndef OBJECTLINESTRIP_H
#define OBJECTLINESTRIP_H

#include "Renderer/staticspritelinestripe.h"
#include "Xml/way.h"

class ObjectLineStrip
{
public:
    ObjectLineStrip(){}
    ObjectLineStrip(Shader& shader,const Way& way,QVector3D color=QVector3D(1.0,1.0,1.0),int priority=0);
    ~ObjectLineStrip();
    void Draw(QVector2D position,QVector2D size);
    bool operator<(const ObjectLineStrip& obj)const{
        return priority<obj.priority;
    }
private:
    staticSpriteLinestripRenderer* LineStripRenderer;
    int priority;
};

#endif // OBJECTLINESTRIP_H

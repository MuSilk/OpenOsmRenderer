#ifndef OBJECTMAP_H
#define OBJECTMAP_H

#include "Xml/xmlmanager.h"
#include "Renderer/dynamicspritelinestrip.h"
#include "Object/ObjectMap/objectlinestrip.h"
#include "Object/ObjectMap/objectpolygon.h"

struct Tag{
    int priority,type;
    string key,value;
    QVector3D color;
    Tag(int priority,int type,string key,string value,QVector3D color){
        this->priority=priority;
        this->type=type;
        this->key=key;
        this->value=value;
        this->color=color;
    }
};

class ObjectMap
{
public:
    ObjectMap();
    ~ObjectMap();
    void Load(const char* file,Shader shader,QVector2D pos,QVector2D size);
    void Render();
    int GetPath(string st,string ed);
    QVector2D Position,Size;
    bool _renderpath=false;
    std::vector<Tag> tags;
    QVector3D background;
    QVector3D pathcolor;
private:
    Shader* shader;
    string FileName;
    bool Changed;
    std::vector<ObjectLineStrip*> LinestripRendererGroup;
    std::vector<ObjectPolygon*> PolygonRendererGroup;
    dynamicSpriteLineStripRenderer* PathRenderer=nullptr;
    xmlManager reader;
    void LoadData();
};

#endif // OBJECTMAP_H

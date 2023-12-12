#ifndef STATICSPRITEPOLYGONRENDERER_H
#define STATICSPRITEPOLYGONRENDERER_H

#include <QOpenGLExtraFunctions>

#include "Basics/shader.h"

class staticSpritePolygonRenderer:QOpenGLExtraFunctions
{
public:
    QVector3D Color;
    staticSpritePolygonRenderer(Shader& shader,const vector<QVector2D>& vertexs,QVector3D color=QVector3D(1.0,1.0,1.0));
    ~staticSpritePolygonRenderer();
    void Draw(QVector2D position,QVector2D size=QVector2D(10,10),GLfloat rotate=0.0f);
private:
    vector<float> Vertexs;
    int Size;
    Shader shader;
    GLuint VAO,VBO;
    void initRenderData();
};

#endif // STATICSPRITEPOLYGONRENDERER_H

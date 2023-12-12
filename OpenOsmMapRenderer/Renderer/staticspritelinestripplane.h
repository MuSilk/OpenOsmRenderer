#ifndef STATICSPRITELINESTRIPEPLANERENDERER_H
#define STATICSPRITELINESTRIPEPLANERENDERER_H

#include <QOpenGLExtraFunctions>

#include "Basics/shader.h"
#include "Basics/camera.h"

class staticSpriteLineStripPlaneRenderer:QOpenGLExtraFunctions
{
public:
    QVector3D Color;
    staticSpriteLineStripPlaneRenderer(const Shader& shader,const vector<QVector2D>& vertexs,QVector3D color=QVector3D(1.0,1.0,1.0));
    ~staticSpriteLineStripPlaneRenderer();
    void Draw(QVector3D position,QVector3D size,Camera camera,QMatrix4x4 projection);
private:
    vector<float> Vertexs;
    int Size;
    Shader shader;
    GLuint VAO,VBO;
    void initRenderData();
};

#endif // STATICSPRITELINESTRIPEPLANERENDERER_H

#ifndef DYNAMICSPRITELINESTRIPPLANERENDERER_H
#define DYNAMICSPRITELINESTRIPPLANERENDERER_H

#include <QOpenGLExtraFunctions>
#include <QVector3D>

#include "Basics/shader.h"

class dynamicSpriteLineStripRenderer:QOpenGLExtraFunctions
{
public:
    dynamicSpriteLineStripRenderer();

public:
    QVector3D Color;
    dynamicSpriteLineStripRenderer(const Shader& shader,QVector3D color=QVector3D(1.0,1.0,1.0));
    ~dynamicSpriteLineStripRenderer();
    void UpdateData(const vector<float>& data);
    void Draw(QVector2D position,QVector2D size);
private:
    vector<float> Vertexs;
    bool Changed;
    int Size;
    Shader shader;
    GLuint VAO,VBO;
    void initRenderData();
};

#endif // DYNAMICSPRITELINESTRIPPLANERENDERER_H

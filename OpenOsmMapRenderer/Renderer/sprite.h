#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <QOpenGLExtraFunctions>

#include "Basics/texture2d.h"
#include "Basics/shader.h"

class SpriteRenderer:QOpenGLExtraFunctions
{
public:
    SpriteRenderer(Shader& shader);
    ~SpriteRenderer();
    void Draw(Texture2D& texture,QVector2D position,QVector2D size=QVector2D(10,10),
              GLfloat rotate=0.0f,QVector3D color=QVector3D(1.0f,1.0f,1.0f));
private:
    Shader shader;
    GLuint VAO,VBO;
    void initRenderData();
};

#endif // SPRITERENDERER_H

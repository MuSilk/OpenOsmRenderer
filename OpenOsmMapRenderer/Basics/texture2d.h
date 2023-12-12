#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QImage>

class Texture2D:QOpenGLFunctions
{
public:
    GLuint ID;

    GLuint Width,Height;

    GLuint Internal_Format,Image_Format;
    GLuint Wrap_S,Wrap_T,Filter_Min,Filter_Max;
    Texture2D();
    explicit Texture2D(QImage& img);
    void Generate(GLuint width,GLuint height,const char* data);
    void Bind();
private:

};

#endif // TEXTURE2D_H

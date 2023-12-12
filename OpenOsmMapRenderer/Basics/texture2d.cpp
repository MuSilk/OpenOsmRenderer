#include "texture2d.h"

Texture2D::Texture2D():Width(0),Height(0),Internal_Format(GL_RGB),Image_Format(GL_RGB),
    Wrap_S(GL_REPEAT),Wrap_T(GL_REPEAT),Filter_Min(GL_NEAREST),Filter_Max(GL_NEAREST)
{
    initializeOpenGLFunctions();
    glGenTextures(1,&ID);
}

Texture2D::Texture2D(QImage& image):Width(0),Height(0),Internal_Format(GL_RGB),Image_Format(GL_RGB),
    Wrap_S(GL_REPEAT),Wrap_T(GL_REPEAT),Filter_Min(GL_NEAREST),Filter_Max(GL_NEAREST){

    initializeOpenGLFunctions();
    glGenTextures(1,&ID);

    QImage img=image.convertToFormat(QImage::Format_ARGB32);
    img=img.rgbSwapped();
    char* data=(char*)img.bits();
    int width=image.width();
    int height=image.height();

    if (!data)qDebug() << "fail to load the texture";

    if (image.hasAlphaChannel()) {
        Internal_Format = GL_RGBA;
        Image_Format = GL_RGBA;
    }
    else{
        Internal_Format = GL_RGB;
        Image_Format = GL_RGB;
    }

    Generate(width, height, data);
}

void Texture2D::Generate(GLuint width,GLuint height,const char* data){
    Width=width;
    Height=height;

    glBindTexture(GL_TEXTURE_2D,ID);
    glTexImage2D(GL_TEXTURE_2D,0,Internal_Format,width,height,0,Image_Format,GL_UNSIGNED_BYTE,data);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,Wrap_S);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,Wrap_T);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,Filter_Min);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,Filter_Max);

    glBindTexture(GL_TEXTURE_2D,0);
}

void Texture2D::Bind(){
    glBindTexture(GL_TEXTURE_2D,ID);
}

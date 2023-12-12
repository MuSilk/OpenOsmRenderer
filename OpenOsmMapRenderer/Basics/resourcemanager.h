#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

#include "texture2d.h"
#include "shader.h"

using std::string;

class ResourceManager: public QOpenGLFunctions
{
public:
    ResourceManager(){initializeOpenGLFunctions();}
    Shader LoadShader(const char*,const char*,const char*,string);
    Shader GetShader(string);

    Texture2D LoadTexture2D(const GLchar*,string);
    Texture2D GetTexture2D(string);

    void extracted();
    void Clear();

private:
    std::map<string,Shader> Shaders;
    std::map<string,Texture2D> Texture2Ds;

    Shader LoadShaderFromFile(const char*,const char*,const char*);
    Texture2D LoadTextureFromFile(const char*);
};

#endif // RESOURCEMANAGER_H

#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLFunctions>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

using namespace std;

class Shader:QOpenGLFunctions {
public:
    GLuint ID;

    Shader(){initializeOpenGLFunctions();}

    void compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource);

    void use();
    void unuse();

    void setBool(const string& name, bool value);
    void setInt(const string& name, int value);
    void set1f(const string& name, float value);
    void set2f(const string& name, float valuex, float valuey);
    void set3f(const string& name, float valuex, float valuey, float valuez);
    void set4f(const string& name, float valuex, float valuey, float valuez, float valuew);
    void setVec2(const string& name, QVector2D vec);
    void setVec3(const string& name, QVector3D vec);
    void setVec4(const string& name, QVector4D vec);
    void setMat4(const std::string& name, QMatrix4x4 mat);
};

#endif // SHADER_H

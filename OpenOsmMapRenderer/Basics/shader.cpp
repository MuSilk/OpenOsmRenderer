#include "shader.h"

#include <iostream>

void Shader::compile(const char* vertexSource,const char* fragmentSource,const char* geometrySource){
    ID=glCreateProgram();

    GLuint vertex,fragment,geometry;
    int success;
    char infolog[512];
    if(vertexSource!=nullptr){
        vertex=glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex,1,&vertexSource,nullptr);
        glCompileShader(vertex);

        glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
        if(!success){
            glGetShaderInfoLog(vertex,512,nullptr,infolog);
            std::cout << "ERROR::SHADERVERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
        }
        glAttachShader(ID,vertex);
        glDeleteShader(vertex);
    }
    if(fragmentSource!=nullptr){
        fragment=glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment,1,&fragmentSource,nullptr);
        glCompileShader(fragment);

        glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
        if(!success){
            glGetShaderInfoLog(fragment,512,nullptr,infolog);
            std::cout << "ERROR::SHADERFRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl;
        }
        glAttachShader(ID,fragment);
        glDeleteShader(fragment);
    }
    if(geometrySource!=nullptr){
        geometry=glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometry,1,&geometrySource,nullptr);
        glCompileShader(geometry);

        glGetShaderiv(geometry,GL_COMPILE_STATUS,&success);
        if(!success){
            glGetShaderInfoLog(geometry,512,nullptr,infolog);
            std::cout << "ERROR::SHADERGEOMETRY::COMPILATION_FAILED\n" << infolog << std::endl;
        }
        glAttachShader(ID,geometry);
        glDeleteShader(geometry);
    }

    glLinkProgram(ID);
    glGetProgramiv(ID,GL_LINK_STATUS,&success);
    if(!success){
        glGetProgramInfoLog(ID,512,nullptr,infolog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infolog << std::endl;
    }
}

void Shader::use(){
    glUseProgram(ID);
}

void Shader::unuse(){
    glUseProgram(0);
}

void Shader::setBool(const string& name, bool value){
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setInt(const string& name, int value){
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::set1f(const string& name, float value){
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::set2f(const string& name, float valuex, float valuey) {
    glUniform2f(glGetUniformLocation(ID, name.c_str()), valuex, valuey);
}
void Shader::set3f(const string& name, float valuex, float valuey, float valuez) {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), valuex, valuey, valuez);
}
void Shader::set4f(const string& name, float valuex, float valuey, float valuez, float valuew) {
    glUniform4f(glGetUniformLocation(ID, name.c_str()), valuex, valuey, valuez, valuew);
}
void Shader::setVec2(const string& name, QVector2D vec) {
    glUniform2f(glGetUniformLocation(ID, name.c_str()), vec.x(), vec.y());
}
void Shader::setVec3(const string& name, QVector3D vec) {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), vec.x(), vec.y(), vec.z());
}
void Shader::setVec4(const string& name, QVector4D vec) {
    glUniform4f(glGetUniformLocation(ID, name.c_str()), vec.x(), vec.y(), vec.z(), vec.w());
}
void Shader::setMat4(const std::string& name, QMatrix4x4 mat) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, mat.data());
}

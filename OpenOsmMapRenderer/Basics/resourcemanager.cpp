#include <iostream>
#include <exception>

#include <QImage>
#include <QFile>

#include "resourcemanager.h"

using std::stringstream;

Shader ResourceManager::LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, string name) {
    Shaders[name] = LoadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}

Shader ResourceManager::GetShader(string name) {
    return Shaders[name];
}

Texture2D ResourceManager::LoadTexture2D(const char* file, string name) {
    Texture2Ds[name] = LoadTextureFromFile(file);
    return Texture2Ds[name];
}

Texture2D ResourceManager::GetTexture2D(string name) {
    return Texture2Ds[name];
}


void ResourceManager::Clear() {
    for (const auto &iter : Shaders)glDeleteProgram(iter.second.ID);
    for (const auto &iter : Texture2Ds)glDeleteTextures(1, &iter.second.ID);
    Shaders.clear();
    Texture2Ds.clear();
}

Shader ResourceManager::LoadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile) {
    string vertexCode, fragmentCode, geometryCode;
    Q_INIT_RESOURCE(res);
    try {
        if (vShaderFile != NULL) {
            QFile vertexShaderFile(vShaderFile);
            vertexShaderFile.open(QIODevice::ReadOnly);
            vertexCode =vertexShaderFile.readAll();
            vertexShaderFile.close();
        }
        if (fShaderFile != NULL) {
            QFile fragmentShaderFile(fShaderFile);
            fragmentShaderFile.open(QIODevice::ReadOnly);
            fragmentCode=fragmentShaderFile.readAll();
            fragmentShaderFile.close();
        }
        if (gShaderFile != NULL) {
            QFile geometryShaderFile(fShaderFile);
            geometryShaderFile.open(QIODevice::ReadOnly);
            geometryCode=geometryShaderFile.readAll();
            geometryShaderFile.close();
        }
    }
    catch (std::exception e) {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const GLchar* vShaderCode = vertexCode.c_str();
    const GLchar* fShaderCode = fragmentCode.c_str();
    const GLchar* gShaderCode = geometryCode.c_str();

    Shader shader;
    shader.compile(vShaderCode,fShaderCode,gShaderFile != nullptr ? gShaderCode : nullptr);
    return shader;
}

Texture2D ResourceManager::LoadTextureFromFile(const char* file) {
    Texture2D texture;

    int width, height;

    QImage image(file);
    image=image.rgbSwapped();
    char* data=(char*)image.bits();
    width=image.width();
    height=image.height();

    if (!data)std::cout << "fail to load the texture";

    if (image.hasAlphaChannel()) {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    else{
        texture.Internal_Format = GL_RGB;
        texture.Image_Format = GL_RGB;
    }

    texture.Generate(width, height, data);

    return texture;
}


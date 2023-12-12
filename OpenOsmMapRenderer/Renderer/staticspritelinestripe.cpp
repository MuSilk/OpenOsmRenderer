#include "staticspritelinestripe.h"
#include <iostream>

staticSpriteLinestripRenderer::staticSpriteLinestripRenderer(Shader& shader,const vector<QVector2D>& vertexs,QVector3D color){
    initializeOpenGLFunctions();
    this->shader=shader;
    Size=vertexs.size();
    for(int i=0;i<Size;i++){
        Vertexs.push_back(vertexs[i].x()),Vertexs.push_back(vertexs[i].y());
    }
    initRenderData();
    Vertexs.clear();
    Color=color;
}

staticSpriteLinestripRenderer::~staticSpriteLinestripRenderer(){
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
}


void staticSpriteLinestripRenderer::Draw(QVector2D position,QVector2D size,GLfloat rotate){
    shader.use();
    QMatrix4x4 model=QMatrix4x4();
    model.translate(QVector3D(position,0.0f));
    model.translate(QVector3D(0.5*size,0.0f));
    model.rotate(rotate,QVector3D(0.0f,0.0f,1.0f));
    model.translate(QVector3D(-0.5f*size,1.0f));
    model.scale(QVector3D(size,1.0f));

    shader.setMat4("model",model);
    shader.setVec3("color",Color);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, Size);
    glBindVertexArray(0);
    shader.unuse();
}

void staticSpriteLinestripRenderer::initRenderData(){

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertexs.size()*sizeof(float), Vertexs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}


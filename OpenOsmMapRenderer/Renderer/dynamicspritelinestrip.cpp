#include "dynamicspritelinestrip.h"

dynamicSpriteLineStripRenderer::dynamicSpriteLineStripRenderer(const Shader& shader,QVector3D color) {
    initializeOpenGLFunctions();
    this->shader=shader;
    initRenderData();
    Color=color;
}

dynamicSpriteLineStripRenderer::~dynamicSpriteLineStripRenderer(){
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
}

void dynamicSpriteLineStripRenderer::UpdateData(const vector<float>& data){
    Vertexs=data;
    Size=data.size()/2;
    Changed=true;
}

void dynamicSpriteLineStripRenderer::Draw(QVector2D position,QVector2D size){
    shader.use();
    QMatrix4x4 model=QMatrix4x4();
    model.translate(QVector3D(position,0.0f));
    model.scale(QVector3D(size,1.0f));

    shader.setMat4("model",model);
    shader.setVec3("color",Color);
    glBindVertexArray(VAO);
    if(Changed){
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBufferSubData(GL_ARRAY_BUFFER,0,Vertexs.size()*sizeof(float),Vertexs.data());
        Changed=false;
    }
    glDrawArrays(GL_LINE_STRIP, 0, Size);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    shader.unuse();
}

void dynamicSpriteLineStripRenderer::initRenderData(){
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, 32768*sizeof(float), NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

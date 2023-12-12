#include "staticspritelinestripplane.h"

staticSpriteLineStripPlaneRenderer::staticSpriteLineStripPlaneRenderer(const Shader& shader,const vector<QVector2D>& vertexs,QVector3D color){
    initializeOpenGLFunctions();
    this->shader=shader;
    Size=vertexs.size();
    for(int i=0;i<Size;i++){
        Vertexs.push_back(vertexs[i].x());
        Vertexs.push_back(vertexs[i].y());
        Vertexs.push_back(0.0f);
    }
    initRenderData();
    Vertexs.clear();
    Color=color;
}

staticSpriteLineStripPlaneRenderer::~staticSpriteLineStripPlaneRenderer(){
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
}

void staticSpriteLineStripPlaneRenderer::Draw(QVector3D position,QVector3D size,Camera camera,QMatrix4x4 projection){
    shader.use();
    QMatrix4x4 view=camera.GetViewMatrix();
    shader.setMat4("view",view);
    shader.setMat4("projection",projection);

    QMatrix4x4 model=QMatrix4x4();
    model.translate(position);
    model.scale(size);
    shader.setMat4("model",model);
    shader.setVec3("color",Color);

    glBindVertexArray(VAO);
    glLineWidth(4);
    glDrawArrays(GL_LINE_STRIP, 0, Size);
    glBindVertexArray(0);
    shader.unuse();
}

void staticSpriteLineStripPlaneRenderer::initRenderData(){
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertexs.size()*sizeof(float), Vertexs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

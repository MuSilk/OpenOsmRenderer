#include "sprite.h"

SpriteRenderer::SpriteRenderer(Shader& shader){
    initializeOpenGLFunctions();
    this->shader=shader;
    initRenderData();
}

SpriteRenderer::~SpriteRenderer(){
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
}

void SpriteRenderer::Draw(Texture2D& texture, QVector2D position, QVector2D size, GLfloat rotate,QVector3D color){
    shader.use();
    QMatrix4x4 model = QMatrix4x4();
    model.translate(QVector3D(position,0.0f));
    model.translate(QVector3D(0.5*size,0.0f));
    model.rotate(rotate,QVector3D(0.0f,0.0f,1.0f));
    model.translate(QVector3D(-0.5f*size,1.0f));
    model.scale(QVector3D(size,1.0f));

    shader.setMat4("model", model);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData() {
    GLfloat vertices[] = {
        0.0f,1.0f,0.0f,1.0f,
        1.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,0.0f,0.0f,

        0.0f,1.0f,0.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,0.0f,1.0f,0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
    glBindVertexArray(0);
}

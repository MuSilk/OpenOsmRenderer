#include "glwindow.h"

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include "Xml/xmlreader.h"

GLWindow::GLWindow(QWidget *parent):QOpenGLWidget(parent){
    QSurfaceFormat surfaceFormat;
    surfaceFormat.setSamples(9);
    setFormat(surfaceFormat);
}

GLWindow::~GLWindow(){
    res->Clear();
}

void GLWindow::initializeGL(){
    initializeOpenGLFunctions();

    //glEnable(GL_PROGRAM_POINT_SIZE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_MULTISAMPLE);

    Init();
}

void GLWindow::paintGL(){
    glClearColor(Map.background.x(),Map.background.y(),Map.background.z(),1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    Update();
    Render();
}

void GLWindow::resizeGL(int width,int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    QMatrix4x4 projection;
    projection.ortho(0.0f,this->width(),0.0f,this->height(),-1.0f,1.0f);
    Shader shader=res->GetShader("sprite");
    shader.use();
    shader.setMat4("projection",projection);
    shader.unuse();
    shader=res->GetShader("polygon");
    shader.use();
    shader.setMat4("projection",projection);
    shader.unuse();
}

void GLWindow::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        int xoffset=event->pos().x()-MouseLeftButtonPos.x();
        int yoffset=event->pos().y()-MouseLeftButtonPos.y();
        Map.Position+=QVector2D(xoffset,-yoffset);
        update();
        MouseLeftButtonPos=event->pos();
    }
}


void GLWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton)MouseLeftButtonPos=event->pos();
}

void GLWindow::wheelEvent(QWheelEvent *event){
    if(event->angleDelta().y()>0)Map.Size*=1.1;
    else Map.Size/=1.1;
    update();
}

void GLWindow::keyPressEvent(QKeyEvent *event){
    update();
}

void GLWindow::keyReleaseEvent(QKeyEvent *event){
    //qDebug()<<event->key()<<"\n";
    KeyPressed[event->key()]=false;

}

void GLWindow::Init(){
    res=new ResourceManager();
    LoadShaders();

    LoadTextures();
    Map.Load("map.xml",res->GetShader("polygon"),QVector2D(0,0),QVector2D(width(),height()));
}

void GLWindow::LoadShaders(){

    res->LoadShader(":/shaders/res/shaders/sprite.vert",":/shaders/res/shaders/sprite.frag",nullptr,"sprite");
    res->LoadShader(":/shaders/res/shaders/polygon.vert",":/shaders/res/shaders/polygon.frag",nullptr,"polygon");

    QMatrix4x4 projection;
    projection.ortho(0.0f,width(),0.0f,height(),-1.0f,1.0f);
    Shader shader=res->GetShader("sprite");
    shader.use();
    shader.setInt("image",0);
    shader.setMat4("projection",projection);
    shader.unuse();
    shader=res->GetShader("polygon");
    shader.use();
    shader.setMat4("projection",projection);
    shader.unuse();
}

void GLWindow::LoadTextures(){
}

void GLWindow::Update(){
}

void GLWindow::Render(){
    Map.Render();
}

void GLWindow::LoadFile(const char* file){
    Map.Load(file,res->GetShader("polygon"),QVector2D(0,0),QVector2D(width(),height()));
    update();
}

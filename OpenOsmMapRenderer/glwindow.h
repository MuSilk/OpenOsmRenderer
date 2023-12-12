#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QWidget>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/glu.h>
#include <GL/gl.h>

#include <Basics/resourcemanager.h>
#include <Renderer/sprite.h>
#include <Renderer/staticspritepolygon.h>
#include <Renderer/staticspritelinestripe.h>
#include <Object/objectmap.h>

class GLWindow:public QOpenGLWidget,protected QOpenGLFunctions
{
    Q_OBJECT
public:
    QPoint MouseLeftButtonPos;
    bool KeyPressed[1024];
public slots:
    void LoadFile(const char* file);
public:
    ResourceManager *res;
    ObjectMap Map;
    GLWindow(QWidget *parent=nullptr);
    ~GLWindow();
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width,int height)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
    //void mouseReleaseEvent(QMouseEvent *event)override;
    void keyPressEvent(QKeyEvent *event)override;
    void keyReleaseEvent(QKeyEvent *event)override;
    void wheelEvent(QWheelEvent *event)override;
private:
    void LoadShaders();
    void LoadTextures();
    void Init();
    void Update();
    void Render();
};

#endif // GLWINDOW_H

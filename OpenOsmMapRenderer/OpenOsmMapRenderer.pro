QT       += core gui\
            openglwidgets\



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Basics/resourcemanager.cpp \
    Basics/shader.cpp \
    Basics/texture2d.cpp \
    Functions/graph.cpp \
    Object/ObjectMap/objectlinestrip.cpp \
    Object/ObjectMap/objectpolygon.cpp \
    Object/objectmap.cpp \
    Renderer/dynamicspritelinestrip.cpp \
    Renderer/sprite.cpp \
    Renderer/staticspritelinestripe.cpp \
    Renderer/staticspritelinestripplane.cpp \
    Renderer/staticspritepolygon.cpp \
    Xml/node.cpp \
    Xml/tinystr.cpp \
    Xml/tinyxml.cpp \
    Xml/tinyxmlerror.cpp \
    Xml/tinyxmlparser.cpp \
    Xml/way.cpp \
    Xml/xmlmanager.cpp \
    Xml/xmlreader.cpp \
    glwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Basics/resourcemanager.h \
    Basics/shader.h \
    Basics/texture2d.h \
    Functions/graph.h \
    Object/ObjectMap/objectlinestrip.h \
    Object/ObjectMap/objectpolygon.h \
    Object/objectmap.h \
    Renderer/dynamicspritelinestrip.h \
    Renderer/sprite.h \
    Renderer/staticspritelinestripe.h \
    Renderer/staticspritelinestripplane.h \
    Renderer/staticspritepolygon.h \
    Xml/node.h \
    Xml/tinystr.h \
    Xml/tinyxml.h \
    Xml/way.h \
    Xml/xmlmanager.h \
    Xml/xmlreader.h \
    glwindow.h \
    mainwindow.h

LIBS+=\
    -lopengl32\

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

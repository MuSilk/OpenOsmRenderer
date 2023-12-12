#include "mainwindow.h"

#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/icons/res/icons/icon.ico"));
    w.setWindowTitle("osmMapRenderer");
    w.show();
    return a.exec();
}

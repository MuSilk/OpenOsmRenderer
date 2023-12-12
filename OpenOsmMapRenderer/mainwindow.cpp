#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QStandardPaths>
#include <QResizeEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->openGLWidget->grabKeyboard();
    connect(ui->search,&QPushButton::clicked,this,&MainWindow::Search);
    connect(ui->actionopen,&QAction::triggered,this,[&](){
        QString str=QFileDialog::getOpenFileName(this,"Open File",
                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                    "xml 文件(*.xml *.osm);");
        if(str!="")ui->openGLWidget->LoadFile(str.toStdString().c_str());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Search(){
    string st=ui->startPosition->text().toStdString();
    string ed=ui->endPosition->text().toStdString();
    if(st==""&&ed==""){
        ui->label->setText("");
        ui->openGLWidget->Map._renderpath=false;
        ui->openGLWidget->update();
        return;
    }
    int result=ui->openGLWidget->Map.GetPath(st,ed);
    if(result==-1){
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setText("起点不存在");
        msgbox.exec();
    }
    else if(result==-2){
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setText("终点不存在");
        msgbox.exec();
    }
    else {
        ui->label->setText("约"+QString::number(result)+"m");
        ui->openGLWidget->update();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event){
    ui->openGLWidget->resize(event->size());
    qDebug()<<event->size()<<"\n";
}

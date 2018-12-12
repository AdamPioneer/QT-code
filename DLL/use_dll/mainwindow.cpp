#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sld.h"
#include <QMessageBox>

#include <QLibrary>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

        QMessageBox * msg=new QMessageBox(this);
        SLD s;

        msg->setText(s.GetStr());
        //msg->setText(QString::Number(add(5,6)));//外部函数可以直接调用
        msg->show();

}

//显示调用
void MainWindow::on_pushButton_2_clicked()
{
    typedef int(*FUN2)(int, int); //  函数指针
    //QLibrary lib("./11/SLD.dll");       //指定dll路径，可以不在exe目录下
    //编译目录
    QLibrary lib("SLD.dll");       //指定dll路径，可以不在exe目录下
    if (lib.load()) {
        qDebug() << "load ok!";
        FUN2 add = (FUN2)lib.resolve("add");
        if (add) {
            qDebug() << "load add ok!";
            qDebug() << add(3, 5);
        }
    } else {
        qDebug() << "load error!";
    }

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QProcess>


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

void MainWindow::init_setup()
{
    backgroudMainPro = new QProcess(this);

    ui->StartPushButton->setStyleSheet("background-color:green");

    ui->comboBox->addItem("Please select the file");
    ui->comboBox->setCurrentIndex(ui->comboBox->findText("Please select the file"));

    ui->comboBox_uart->addItem("Please select uart");
    ui->comboBox_uart->setCurrentIndex(ui->comboBox_uart->findText("Please select uart"));

    ui->testDetailInfo->setVisible(false);

}
QString MainWindow::get_Uartfile()
{
    return ui->comboBox_uart->currentText();
}

QString MainWindow::get_ConfigFile()
{
    return ui->comboBox->currentText();
}

void MainWindow::on_StartPushButton_clicked()
{
    QProcess process(this);

    if(ui->StartPushButton->text() != "STOP") {
           ui->StartPushButton->setStyleSheet("");
           ui->StartPushButton->setStyleSheet("background-color:red");
           ui->StartPushButton->setText("STOP");
           process.start("cmd.exe");
           //process.execute("H:\\11.QT\\build-helloworld1-Desktop_Qt_5_9_4_MinGW_32bit-Debug\\debug\\helloworld1.exe");
           //process.start("H:\\11.QT\\build-helloworld1-Desktop_Qt_5_9_4_MinGW_32bit-Debug\\debug\\helloworld1.exe");
       } else {
           ui->StartPushButton->setStyleSheet("");
           ui->StartPushButton->setStyleSheet("background-color:green");
           ui->StartPushButton->setText("START");
           process.close();
       }
}

void MainWindow::on_toolButton_clicked()
{
    //QString directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Save Path"), QDir::currentPath()));
    //QString file = QFileDialog::getOpenFileName(this);
    QDir dir;
    QString file = QFileDialog::getOpenFileName(this, QString("Load config file"),dir.absolutePath(), QString("config file(*)"));
    //ui->label->setText("lllllll");

    if(file.isEmpty())
    {
        if(ui->comboBox->findText(file) == -1)
            ui->comboBox->addItem("Please select the file");

        ui->comboBox->setCurrentIndex(ui->comboBox->findText("Please select the file"));
    } else {
        ui->comboBox->addItem(file);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(file));
    }

}


void MainWindow::on_toolButton_uart_clicked()
{
    //QString directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Save Path"), "/dev"));
    //QDir dir("/");
    QDir dir("C:");
    QString UartFile = QFileDialog::getOpenFileName(this, QString("Load UART"),dir.absolutePath(), QString("uart device(tty*)"));
    //ui->label->setText("lllllll");


    if(UartFile.isEmpty())
    {
        if(ui->comboBox_uart->findText(UartFile) == -1)
            ui->comboBox_uart->addItem("Please select uart");

        ui->comboBox_uart->setCurrentIndex(ui->comboBox_uart->findText("Please select uart"));
    } else {
        ui->comboBox_uart->addItem(UartFile);
        ui->comboBox_uart->setCurrentIndex(ui->comboBox_uart->findText(UartFile));
    }

}

void MainWindow::on_pushButton_testInfo_clicked()
{
    if(ui->testDetailInfo->isVisible()) {
        ui->testDetailInfo->setVisible(false);
    } else {
        ui->testDetailInfo->setEnabled(true);
        ui->testDetailInfo->setVisible(true);
        ui->testDetailInfo->setPlainText("test detail info \n .....");
    }

}

void MainWindow::on_MainWindow_destroyed()
{

}

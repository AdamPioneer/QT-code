#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //server
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost,6666))
    {  //**本地主机的6666端口，如果出错就输出错误信息，并关闭
        qDebug() << tcpServer->errorString();
        close();
    }
    //连接信号和相应槽函数
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));


//client
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
             this,SLOT(displayError(QAbstractSocket::SocketError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage()
{
    //用于暂存我们要发送的数据
    QByteArray block;

    //使用数据流写入数据
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_5_7);

    out<<(quint16) 0;
    out<<tr("hello Tcp!!!");
    out.device()->seek(0);
    out<<(quint16) (block.size() - sizeof(quint16));

    //我们获取已经建立的连接的子套接字
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    connect(clientConnection,SIGNAL(disconnected()),clientConnection,
           SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();

    //发送数据成功后，显示提示
    ui->statusLabel->setText("send message successful!!!");
}

void MainWindow::newConnect()
{
    blockSize = 0; //初始化其为0
tcpSocket->abort(); //取消已有的连接

//连接到主机，这里从界面获取主机地址和端口号
    tcpSocket->connectToHost(ui->hostLineEdit->text(),
                             ui->portLineEdit->text().toInt());
}

void MainWindow::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_7);
    //设置数据流版本，这里要和服务器端相同
    if(blockSize==0) //如果是刚开始接收数据
    {
       //判断接收的数据是否有两字节，也就是文件的大小信息
       //如果有则保存到blockSize变量中，没有则返回，继续接收数据
       if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
       in >> blockSize;
    }
    if(tcpSocket->bytesAvailable() < blockSize) return;
    //如果没有得到全部的数据，则返回，继续接收数据
    in >> message;
    //将接收到的数据存放到变量中
    ui->messageLable->setText(message);
    //显示接收到的数据
}

void MainWindow::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString(); //输出错误信息
}

void MainWindow::on_pushButton_clicked()
{
     newConnect(); //请求连接
}

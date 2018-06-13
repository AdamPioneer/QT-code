#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /* add operate function */
    void init_setup();
    QString get_Uartfile();
    QString get_ConfigFile();

private slots:
    //void on_PushButton_clicked();

    void on_StartPushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_uart_clicked();

    void on_pushButton_testInfo_clicked();

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
    QProcess *backgroudMainPro;
};

#endif // MAINWINDOW_H

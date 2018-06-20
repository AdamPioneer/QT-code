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
    QString get_configFile();
    QString get_sequenceFile();

private slots:
    //void on_PushButton_clicked();

    void on_StartPushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_uart_clicked();

    void on_pushButton_testInfo_clicked();

    void on_MainWindow_destroyed();

    void on_toolButton_config_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *backgroudMainPro;
};

#endif // MAINWINDOW_H

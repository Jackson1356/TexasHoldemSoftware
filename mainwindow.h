#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<rulescene.h>
#include<selectscene.h>
#include<QSound>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent*);
    rulescene * rule=NULL;
    selectscene * select=NULL;
    QSound* bgm;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

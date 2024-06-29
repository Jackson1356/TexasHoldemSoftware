#ifndef PLAYSCENE2_H
#define PLAYSCENE2_H

#include <QMainWindow>
#include<QLabel>
#include<QPropertyAnimation>
#include<QPushButton>

namespace Ui {
class playscene2;
}

class playscene2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit playscene2(QWidget *parent = 0);
    ~playscene2();

    void paintEvent(QPaintEvent*);
    void PlayerImg2(QLabel *a,int x);
    void Deal2(QLabel *a,int x,int y);
    void Turn2(QLabel*a,QString card);
    QPropertyAnimation * deal2;

signals:
    void playback2();
private:
    Ui::playscene2 *ui;
};

#endif // PLAYSCENE2_H

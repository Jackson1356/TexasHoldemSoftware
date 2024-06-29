#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QPushButton>
#include<QMouseEvent>
class MyQPushButton : public QPushButton
{
    Q_OBJECT
public:

    MyQPushButton(QString normal, QString pressed="");
    QString normalimg;
    QString pressedimg;

    void zoom1();
    void zoom2();

//    void mousePressEvent(QMouseEvent*);
//    void mouseReleaseEvent(QMouseEvent*);
signals:

public slots:
};

#endif // MYQPUSHBUTTON_H

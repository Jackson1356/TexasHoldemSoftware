#include "myqpushbutton.h"
#include<QPropertyAnimation>
#include <QMouseEvent>
MyQPushButton:: MyQPushButton(QString normal, QString pressed)
{
    this->normalimg=normal;
    this->pressedimg=pressed;
    QPixmap pix;
    pix.load(normal);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px};");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyQPushButton::zoom1()
{
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyQPushButton::zoom2()
{
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}



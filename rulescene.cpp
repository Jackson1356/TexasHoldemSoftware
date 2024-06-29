#include "rulescene.h"
#include "ui_rulescene.h"
#include<QPainter>
#include<QDebug>
#include<myqpushbutton.h>
#include "mainwindow.h"
#include<QLabel>
#include<QSound>

rulescene::rulescene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rulescene)
{
    ui->setupUi(this);
    QSound* btnsound=new QSound("./resourse/clicksound.wav",this);
    ui->label->setStyleSheet("color:white;");
    ui->textBrowser->setStyleSheet("color:white;");
    ui->scrollArea->setStyleSheet("background:transparent;");
    setWindowTitle("规则介绍");
    setWindowIcon(QIcon("./resourse/windowicon.png"));
    setFixedSize(2400,1332);
    MyQPushButton* backbtn=new MyQPushButton("./resourse/backbtn.png");
    backbtn->setParent(this);
    backbtn->move(15,0);
    connect(backbtn,&MyQPushButton::clicked,[=](){
        btnsound->play();
        backbtn->zoom1();
        backbtn->zoom2();
        qDebug()<<"返回主页";

        emit this->ruleback();

    });
}

void rulescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("./resourse/rulescene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}



rulescene::~rulescene()
{
    delete ui;
}

#include "playscene2.h"
#include "ui_playscene2.h"
#include<QPainter>
#include<QDebug>
#include<myqpushbutton.h>
#include "mainwindow.h"
#include<time.h>
#include<stdlib.h>
#include<QTimer>
#include<QSound>

playscene2::playscene2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playscene2)
{
    ui->setupUi(this);
    QSound* btnsound=new QSound("./resourse/clicksound.wav",this);
    srand((unsigned)(time(NULL)));
    setWindowTitle("无尽模式");
    setWindowIcon(QIcon("./resourse/windowicon.png"));
    setFixedSize(2400,1332);
    int i=rand()%7;
    PlayerImg2(ui->label,i);
    PlayerImg2(ui->label_2,i+1);
    PlayerImg2(ui->label_3,i+2);
    PlayerImg2(ui->label_4,i+3);
    MyQPushButton* backbtn=new MyQPushButton("./resourse/backbtn3.png");
    backbtn->setParent(this);
    backbtn->move(-50,-50);
    connect(backbtn,&MyQPushButton::clicked,[=](){
        btnsound->play();
        backbtn->zoom1();
        backbtn->zoom2();
        qDebug()<<"返回上一步";

        emit this->playback2();

    });
    MyQPushButton * dealbtn2=new MyQPushButton("./resourse/dealbtn.png");
    dealbtn2->setParent(this);
    dealbtn2->move(this->width()*0.5-dealbtn2->width()*0.5,this->height()*0.5);
    connect(dealbtn2,&MyQPushButton::clicked,[=](){
        dealbtn2->hide();
        Deal2(ui->label_5,1755,300);
        Deal2(ui->label_6,1875,300);
        QTimer::singleShot(500,this,[=](){
            Deal2(ui->label_7,1755,900);
            Deal2(ui->label_8,1875,900);
        });
        QTimer::singleShot(1000,this,[=](){
            Deal2(ui->label_9,1100,1000);
            Deal2(ui->label_10,1220,1000);
        });
        QTimer::singleShot(1500,this,[=](){
            Deal2(ui->label_11,480,900);
            Deal2(ui->label_12,600,900);
        });
        QTimer::singleShot(2000,this,[=](){
            Deal2(ui->label_13,480,300);
            Deal2(ui->label_14,600,300);
            MyQPushButton * lookbtn=new MyQPushButton("./resourse/lookbtn.png");
            lookbtn->setParent(this);
            lookbtn->show();
            lookbtn->move(this->width()*0.5-lookbtn->width()*0.5+10,1010);
            connect(lookbtn,&MyQPushButton::clicked,[=](){
                Turn2(ui->label_9,"./resourse/da.png");
                Turn2(ui->label_10,"./resourse/dk.png");
                lookbtn->hide();
            });

        });
    });



}
void playscene2::Deal2(QLabel *a,int x,int y)
{
    deal2=new QPropertyAnimation();
    deal2->setTargetObject(a);
    deal2->setPropertyName("pos");
    deal2->setDuration(1000);
    deal2->setStartValue(a->pos());
    deal2->setEndValue(QPoint(x,y));
    deal2->setEasingCurve(QEasingCurve::Linear);
    deal2->start();
}

void playscene2::Turn2(QLabel *a, QString card)
{
    QPixmap pix;
    pix.load(card);
    a->setPixmap(pix);
}

void playscene2::PlayerImg2(QLabel * a,int x)
{
    QPixmap pix;
    if(x==0||x==8)
    {
        pix.load("./resourse/player1.png");
    }
    else if(x==1||x==9)
    {
        pix.load("./resourse/player2.png");
    }
    else if(x==2||x==10)
    {
        pix.load("./resourse/player3.png");
    }
    else if(x==3)
    {
        pix.load("./resourse/player4.png");
    }
    else if(x==4)
    {
        pix.load("./resourse/player5.png");
    }
    else if(x==5)
    {
        pix.load("./resourse/player6.png");
    }
    else if(x==6)
    {
        pix.load("./resourse/player7.png");
    }
    else if(x==7)
    {
        pix.load("./resourse/player1.png");
    }
    a->setPixmap(pix);


}

void playscene2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("./resourse/playscene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

playscene2::~playscene2()
{
    delete ui;
}

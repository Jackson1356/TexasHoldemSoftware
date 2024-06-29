#include "selectscene.h"
#include "ui_selectscene.h"
#include<QPainter>
#include<myqpushbutton.h>
#include "mainwindow.h"
#include<QDebug>
#include<QTimer>
#include<QSound>

selectscene::selectscene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selectscene)
{
    ui->setupUi(this);
    QSound* btnsound=new QSound(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/clicksound.wav",this);
    setWindowTitle("模式选择界面");
    setWindowIcon(QIcon(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/windowicon.png"));
    setFixedSize(2400,1332);
    MyQPushButton* backbtn=new MyQPushButton(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/backbtn (2).png");
    backbtn->setParent(this);
    backbtn->move(15,0);
    connect(backbtn,&MyQPushButton::clicked,[=](){
        btnsound->play();
        backbtn->zoom1();
        backbtn->zoom2();
        qDebug()<<"返回主页";

        emit this->selectback();

    });
    play=new playscene;
    play2=new playscene2;
    MyQPushButton* selectbtn=new MyQPushButton(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/selectbtn.png");
    selectbtn->setParent(this);
    selectbtn->move(this->width()*0.5-selectbtn->width()*0.5,this->height()*0.4);
    connect(selectbtn,&MyQPushButton::clicked,[=](){
        btnsound->play();
        selectbtn->zoom1();
        selectbtn->zoom2();
        qDebug()<<"进入十五轮模式";
        QTimer::singleShot(300,this,[=](){
            this->hide();
            play->show();
        });

    });

    MyQPushButton* selectbtn2=new MyQPushButton(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/selectbtn2.png");
    selectbtn2->setParent(this);
    selectbtn2->move(this->width()*0.5-selectbtn->width()*0.5,this->height()*0.6);
    connect(selectbtn2,&MyQPushButton::clicked,[=](){
        btnsound->play();
        selectbtn2->zoom1();
        selectbtn2->zoom2();
        qDebug()<<"进入无尽模式";
        QTimer::singleShot(300,this,[=](){
            this->hide();
            play2->show();

        });


    });
    connect(play,&playscene::playback,this,[=](){
        QTimer::singleShot(300,this,[=](){
            play->hide();
            this->show();
        });
    });

    connect(play2,&playscene2::playback2,this,[=](){
        QTimer::singleShot(300,this,[=](){
            play2->hide();
            this->show();
        });
    });
}

void selectscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/playscene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

selectscene::~selectscene()
{
    delete ui;
}

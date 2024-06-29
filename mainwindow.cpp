#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<myqpushbutton.h>
#include<QPushButton>
#include<QDebug>
#include<QTimer>
#include<rulescene.h>
#include<playscene.h>
#include<QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("德州扑克");
    setFixedSize(2400,1332);
    setWindowIcon(QIcon(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/windowicon.png"));
    MyQPushButton *startbtn = new MyQPushButton(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/startbtn.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.5);
    select=new selectscene;
    bgm=new QSound(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/startbgm.wav",this);
    bgm->play();
    bgm->setLoops(-1);
    QSound* btnsound=new QSound(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/clicksound.wav",this);
    connect(startbtn,&MyQPushButton::clicked,[=](){
        qDebug()<<"游戏开始";
        btnsound->play();
        startbtn->zoom1();
        startbtn->zoom2();
        QTimer::singleShot(300,this,[=](){
            this->hide();
            select->show();
        });
    });
    MyQPushButton*quesbtn=new MyQPushButton(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/quesbtn.png");
    quesbtn->setParent(this);
    quesbtn->move(this->width()-quesbtn->width(),this->height()-quesbtn->height());

    rule=new rulescene;
    //监听规则介绍关卡的信号
    connect(rule,&rulescene::ruleback,this,[=](){
        QTimer::singleShot(300,this,[=](){
            rule->hide();
            this->show();
        });
    });
    connect(select,&selectscene::selectback,this,[=](){
        QTimer::singleShot(300,this,[=](){
            select->hide();
            this->show();
        });
    });
    connect(quesbtn,&MyQPushButton::clicked,[=](){
        qDebug()<<"规则介绍";
        quesbtn->zoom1();
        quesbtn->zoom2();
        btnsound->play();
        QTimer::singleShot(300,this,[=](){
            this->hide();
            rule->show();


        });
    });

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/F:/qq文件/暑期大作业 德州扑克/picture resourse/startscene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

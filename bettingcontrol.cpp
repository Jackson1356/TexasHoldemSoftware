#include "bettingcontrol.h"
#include "ui_bettingcontrol.h"

BettingControl::BettingControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BettingControl)
{
    ui->setupUi(this);
    void(QSpinBox::* spsignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox , spsignal , ui->horizontalSlider , &QSlider::setValue);

    ui->spinBox->setStyleSheet("background-color:#24303d;color:#FF7826;");
    ui->horizontalSlider->setStyleSheet("QSlider{\
                                      background-color:#24303d;\
                                      padding-top:15px;\
                                      padding-bottom:15px;\
                                      border-radius:7px;\
                                      }\
                                      QSlider::add-page:horizontal \
                                      {\
                                          background-color: #8d99a5;\
                                          width:5px;\
                                          border-radius: 2px;\
                                      }\
                                      QSlider::sub-page:horizontal \
                                      {\
                                          background-color: #FF7826;\
                                          width:10px;\
                                          border-radius: 2px;\
                                      }\
                                      QSlider::groove:horizontal\
                                      {\
                                          height:20px;\
                                          left:0px;right:0px;border:0px;\
                                          background:rgba(0,0,0,50);\
                                          border-radius:6px;\
                                      }\
                                      QSlider::handle:horizontal  \
                                      {\
                                          height: 40px;  \
                                          width: 40px;\
                                          margin-top:-20px;margin-left:-5px;margin-bottom:-20px;margin-right:5px;\
                                          border-radius: 14px;\
                                          border-image:url(:/F:/qq文件/暑期大作业 德州扑克/picture resourse/bettingcontrol.png);\
                                      }"
                                      );

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}


void BettingControl::setbet(int a)
{
    ui->spinBox->setValue(a);

}

int BettingControl::getbet()
{

    return ui->horizontalSlider->value();
}

void BettingControl::setvalue(int a,int b)
{
    ui->horizontalSlider->setMaximum(a);
    ui->horizontalSlider->setMinimum(b);
}

BettingControl::~BettingControl()
{
    delete ui;
}

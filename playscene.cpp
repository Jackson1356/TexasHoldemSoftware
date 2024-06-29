#include "playscene.h"
#include "ui_playscene.h"
#include<QString>
#include<QPainter>
#include<QDebug>
#include<myqpushbutton.h>
#include<QPushButton>
#include "mainwindow.h"
#include<time.h>
#include<stdlib.h>
#include<QTimer>
#include<QSound>
#include<selectscene.h>

playscene::playscene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playscene)
{
    ui->setupUi(this);
    Game game;
    for(int k=1;k<=15;k++)
    {
        game.Clear();
    }
    QSound* btnsound=new QSound("./resourse/clicksound.wav",this);
    QSound* chipsound=new QSound("./resourse/chips.wav");
    srand((unsigned)(time(NULL)));
    setWindowTitle("十五轮模式");
    setWindowIcon(QIcon("./resourse/windowicon.png"));
    setFixedSize(2400,1332);
    int x=rand()%8;
    game.Set_iPicture(x);
    PlayerImg(ui->label,x);
    PlayerImg(ui->label_2,x+1);
    PlayerImg(ui->label_3,x+2);
    PlayerImg(ui->label_4,x+3);
    MyQPushButton* backbtn=new MyQPushButton("./resourse/backbtn3.png");
    backbtn->setParent(this);
    backbtn->move(-50,-50);
    connect(backbtn,&MyQPushButton::clicked,[=](){
        btnsound->play();
        backbtn->zoom1();
        backbtn->zoom2();
        qDebug()<<"返回上一步";

        emit this->playback();

    });




//    ui->label_20->hide();
//    ui->label_21->hide();
//    ui->label_22->hide();
//    ui->label_23->hide();
//    ui->label_24->hide();
    ui->label_25->hide();
    ui->label_26->hide();
    ui->label_27->hide();
    ui->label_28->hide();
    ui->label_29->hide();
//    ui->label_cbm_1->hide();
//    ui->label_cbm_2->hide();
//    ui->label_cbm_3->hide();
//    ui->label_cbm_4->hide();
//    ui->label_cbm_6->hide();
//    ui->label_cbm_8->hide();
//    ui->label_cbm_9->hide();
//    ui->label_cbm_10->hide();
    ui->bettingcontrol->hide();
    fold=new MyQPushButton("./resourse/foldbtn.png");
    fold->setParent(this);
    fold->move(this->width()-fold->width(),this->height()-fold->height());
//    fold->hide();
    follow=new MyQPushButton("./resourse/followbtn.png");
    follow->setParent(this);
    follow->move(this->width()-follow->width()-fold->width(),this->height()-follow->height());
//    follow->hide();
    add=new MyQPushButton("./resourse/addbtn.png");
    add->setParent(this);
    add->move(this->width()-add->width()-follow->width()-fold->width(),this->height()-add->height());
//    add->hide();
    confirm=new MyQPushButton("./resourse/confirmbtn.png");
    confirm->setParent(this);
    confirm->move(this->width()-add->width()-follow->width()-fold->width()-confirm->width(),this->height()-confirm->height());
    confirm->hide();
    connect(add,&MyQPushButton::clicked,[=](){
        btnsound->play();
        add->zoom1();
        add->zoom2();
        QTimer::singleShot(300,this,[=](){
            confirm->show();
            ui->bettingcontrol->show();
            ui->bettingcontrol->setvalue(90,12);
        });
    });
    connect(confirm,&MyQPushButton::clicked,[=](){
        btnsound->play();
        confirm->zoom1();
        confirm->zoom2();
        QTimer::singleShot(300,this,[=](){
            add->hide();
            follow->hide();
            fold->hide();
            confirm->hide();
            ui->bettingcontrol->hide();
            ui->label_20->show();
            Fly(ui->label_20,1130,750);
            chipsound->play();
            int y=ui->bettingcontrol->getbet()*100;
            QString b=QString::number(y);
            ui->label_cbm_5->setText(b);
        });
    });
    connect(follow,&MyQPushButton::clicked,[=](){
        btnsound->play();
        follow->zoom1();
        follow->zoom2();
        QTimer::singleShot(300,this,[=](){
            add->hide();
            follow->hide();
            fold->hide();
            confirm->hide();
            ui->bettingcontrol->hide();
            ui->label_20->show();
            Fly(ui->label_20,1130,750);
            chipsound->play();
        });
    });
    connect(fold,&MyQPushButton::clicked,[=](){
        btnsound->play();
        fold->zoom1();
        fold->zoom2();
        QTimer::singleShot(300,this,[=](){
            add->hide();
            follow->hide();
            fold->hide();
            confirm->hide();
            ui->bettingcontrol->hide();
            ui->label_20->show();
            Fly(ui->label_20,1130,750);
            Fly(ui->label_21,730,630);
            Fly(ui->label_22,1530,530);
            Fly(ui->label_23,1530,630);
            Fly(ui->label_24,730,530);
            chipsound->play();
        });
    });

    QPushButton *btn=new QPushButton("秒杀全场",this);
    btn->move(600,600);
    btn->setFixedSize(100,100);
    connect(btn,&QPushButton::clicked,[=](){
        PlayerImg_2(ui->label,x);
        PlayerImg_2(ui->label_2,x+1);
        PlayerImg_2(ui->label_3,x+2);
        PlayerImg_2(ui->label_4,x+3);
    });


    int y=14;
    QString a=QString::number(y);
    ui->label_count_2->setText(a);

    MyQPushButton * dealbtn=new MyQPushButton("./resourse/dealbtn.png");
    dealbtn->setParent(this);
    dealbtn->move(this->width()*0.5-dealbtn->width()*0.5,this->height()*0.5);
    connect(dealbtn,&MyQPushButton::clicked,[=](){

        btnsound->play();
        dealbtn->zoom1();
        dealbtn->zoom2();
        QTimer::singleShot(300,this,[=](){
            dealbtn->hide();
            Fly(ui->label_5,1755,300);
            Fly(ui->label_6,1875,300);
            QTimer::singleShot(500,this,[=](){
                Fly(ui->label_7,1755,850);
                Fly(ui->label_8,1875,850);
            QTimer::singleShot(500,this,[=](){
                Fly(ui->label_9,1100,1000);
                Fly(ui->label_10,1220,1000);
            QTimer::singleShot(500,this,[=](){
                Fly(ui->label_11,480,850);
                Fly(ui->label_12,600,850);
            QTimer::singleShot(500,this,[=](){
                Fly(ui->label_13,480,300);
                Fly(ui->label_14,600,300);
            QTimer::singleShot(500,this,[=](){
                Fly(ui->label_15,1150,600);
                Fly(ui->label_16,1030,600);
                Fly(ui->label_17,910,600);
                Fly(ui->label_18,1270,600);
                Fly(ui->label_19,1390,600);
                MyQPushButton * lookbtn=new MyQPushButton("./resourse/lookbtn.png");
                lookbtn->setParent(this);
                lookbtn->show();
                lookbtn->move(this->width()*0.5-lookbtn->width()*0.5+10,1010);
                connect(lookbtn,&MyQPushButton::clicked,[=](){
                    btnsound->play();
                    lookbtn->zoom1();
                    lookbtn->zoom2();
                    QTimer::singleShot(300,this,[=](){
                        Turn(ui->label_9,"./resourse/da.png");
                        Turn(ui->label_10,"./resourse/dk.png");
                        lookbtn->hide();
                    });
                });
            });
            });
            });
            });
            });
        });
    });




}
void playscene::Fly(QLabel *a,int x,int y)
{
    deal=new QPropertyAnimation();
    deal->setTargetObject(a);
    deal->setPropertyName("pos");
    deal->setDuration(1000);
    deal->setStartValue(a->pos());
    deal->setEndValue(QPoint(x,y));
    deal->setEasingCurve(QEasingCurve::Linear);
    deal->start();
}

void playscene::Turn(QLabel *a, QString card)
{
    QPixmap pix;
    pix.load(card);
    a->setPixmap(pix);
}

void playscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("./resourse/playscene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void playscene::PlayerImg(QLabel * a,int x)
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
        pix.load("./resourse/player8.png");
    }
    a->setPixmap(pix);


}

void playscene::PlayerImg_2(QLabel * a,int x)
{
    QPixmap pix;
    if(x==0||x==8)
    {
        pix.load("./resourse/player1_2.png");
    }
    else if(x==1||x==9)
    {
        pix.load("./resourse/player2_2.png");
    }
    else if(x==2||x==10)
    {
        pix.load("./resourse/player3_2.png");
    }
    else if(x==3)
    {
        pix.load("./resourse/player4_2.png");
    }
    else if(x==4)
    {
        pix.load("./resourse/player5_2.png");
    }
    else if(x==5)
    {
        pix.load("./resourse/player6_2.png");
    }
    else if(x==6)
    {
        pix.load("./resourse/player7_2.png");
    }
    else if(x==7)
    {
        pix.load("./resourse/player8_2.png");
    }
    a->setPixmap(pix);


}
void playscene::PlayerImg_4(QLabel *a,int i)
{
    QPixmap pix;
    if(i==0||i==8)
    {
        pix.load("./resourse/player1_3.png");
    }
    if(i==1||i==9)
    {
        pix.load("./resourse/player2_3.png");
    }
    if(i==2||i==10)
    {
        pix.load("./resourse/player3_3.png");
    }
    if(i==3)
    {
        pix.load("./resourse/player4_3.png");
    }
    if(i==4)
    {
        pix.load("./resourse/player5_3.png");
    }
    if(i==5)
    {
        pix.load("./resourse/player6_3.png");
    }
    if(i==6)
    {
        pix.load("./resourse/player7_3.png");
    }
    if(i==7)
    {
        pix.load("./resourse/player8_3.png");
    }
    a->setPixmap(pix);
}

void playscene::PlayerImg_3(int x,int i)         //x为位置，i为iPicture
{
    if(x==0) PlayerImg_4(ui->label_3,i);
    if(x==1) PlayerImg_4(ui->label_4,i);
    if(x==3) PlayerImg_4(ui->label_2,i);
    if(x==4) PlayerImg_4(ui->label,i);
}
playscene::~playscene()
{
    delete ui;
}


Game::Game() {
    iLowest_Chips = 200;
}
//牌局开始
void Game::Clear() {
    int j;
    srand((unsigned)time(NULL));
    for (j = 0; j <= 52; j++) bCards[j] = false;
    iRounds = 0; iCurrent_Players = 0;
    for (j = 0; j < 5; j++)
        if (Player[j].Get_Cash() > 0) iCurrent_Players++;
        else Player[j].Game_Over();
    iTotal_Cash = 0;
    for (j = 0; j < 5; j++) iPlayer_Bet_Total[j] = 0;
    for (j = 0; j < 5; j++) Player[j].Clear();
    iFirst_Player = rand() % 5;

    Pre_Flop();
}
int Game::Max(int x, int y) {
    if (x > y) return x;
    return y;
}
//检查两张卡类型
int Game::Check_Two_Cards(int x, int y) {
    int x1, x2, y1, y2, dis;
    x1 = x % 13; x2 = (x - 1) / 13;
    y1 = y % 13; y2 = (y - 1) / 13;
    if (x1 == 0) x1 = 13;
    if (y1 == 0) y1 = 13;
    if (x1 == 1) x1 = 14;
    if (y1 == 1) y1 = 14;
    dis = abs(x1 - y1);
    if (x1 == y1) {
        if (x1 >= 10) return 0;
        else if (x1 > 5) return 1;
        else return 2;
    }
    if (x2 == y2) {
        if (x1 >= 11 || y1 >= 11) {
            if (dis == 1 || dis == 2) return 0;
            if (dis == 3 || dis == 4) return 1;
            if (dis >= 5) return 3;
        }
        if (dis == 1 || dis == 2) return 2;
        if (dis == 3 || dis == 4) return 4;
        return 5;
    }
    if (x1 >= 10 || y1 >= 10) {
        if (dis >= 5) return 5;
        if (dis == 3 || dis == 4) return 3;
        if (dis == 1 || dis == 2) return 2;
    }
    if (dis == 3 || dis == 4) return 7;
    if (dis == 1 || dis == 2) return 6;
    return 8;
}
//翻每个人的底牌
void Game::Pre_Flop() {
    int i, x;
    i = 0;
    while (i < 10) {
        x = (rand() % 52) + 1;
        if (bCards[x] == false) {
            iPlayer_Cards[i] = x;
            bCards[x] = true;
            i++;
        }
    }
    Player[0].Get_First_Value(Check_Two_Cards(iPlayer_Cards[0], iPlayer_Cards[1]));
    Player[1].Get_First_Value(Check_Two_Cards(iPlayer_Cards[2], iPlayer_Cards[3]));
    Player[3].Get_First_Value(Check_Two_Cards(iPlayer_Cards[6], iPlayer_Cards[7]));
    Player[4].Get_First_Value(Check_Two_Cards(iPlayer_Cards[8], iPlayer_Cards[9]));

    for (i = 0; i < 10; i++) {
        cout << iPlayer_Cards[i] << ' ';
    }
    cout << endl;
    for (i = 0; i < 5; i++) {
        cout << Player[i].First_Value() << ' ';
    }
    cout << endl;

    system("pause");
    First_Bet();
}
//计算五张牌期望
int Game::Check_Five_Cards(int x, int y, int z, int u, int v) {
    int iTotal, i, j; int a[7];
    double ans;
    bool bCards_Now[53];
    for (i = 1; i < 53; i++) bCards_Now[i] = false;
    iTotal = 0;  a[0] = x; a[1] = y; a[2] = z; a[3] = u; a[4] = v;
    for (i = 0; i < 5; i++) bCards_Now[a[i]] = true;
    for (i = 1; i <= 52; i++) {
        if (bCards_Now[i] == false) {
            a[5] = i;
            for (j = i + 1; j < 52; j++) {
                if (bCards_Now[j] == false) {
                    a[6] = j;
                    iTotal += iCards_Weight[Check_Seven_Cards(a)];
                }
            }
        }
    }
    ans = (double)iTotal / 1081;
    for (i = 0; i < 10; i++) if (ans > iWeight[i]) break;
    return i;
}
//计算六张卡期望
int Game::Check_Six_Cards(int x, int y, int z, int u, int v, int w) {
    int iTotal, i; int a[7];
    double ans;
    bool bCards_Now[53];
    for (i = 1; i < 53; i++) bCards_Now[i] = false;
    iTotal = 0;  a[0] = x; a[1] = y; a[2] = z; a[3] = u; a[4] = v; a[5] = w;
    for (i = 0; i < 6; i++) bCards_Now[a[i]] = true;
    for (i = 1; i <= 52; i++) {
        if (bCards_Now[i] == false) {
            a[6] = i;
            iTotal += iCards_Weight[Check_Seven_Cards(a)];
        }
    }
    ans = (double)iTotal / 46;
    for (i = 0; i < 10; i++) if (ans > iWeight[i]) break;
    return i;
}
//检查七张卡类型
int Game::Check_Seven_Cards(int iCurrent[7]) {
    int iCards_Number[7];
    int iCards_Suit[7];
    int iCards_Total[5];
    int i, j, temp, categories;
    int Cards_Shape, Max_Shape;
    bool flush, straight;
    Max_Shape = 10;
    for (i = 0; i < 7; i++) {
        iCards_Number[i] = iCurrent[i] % 13;
        iCards_Suit[i] = (iCurrent[i] - 1) / 13;
        if (iCards_Number[i] == 1) iCards_Number[i] += 13;
    }
    for (i = 0; i < 6; i++)
        for (j = 6; j > i; j--) {
            if (iCards_Number[j] < iCards_Number[j - 1]) {
                temp = iCards_Number[j];
                iCards_Number[j] = iCards_Number[j - 1];
                iCards_Number[j - 1] = temp;
                temp = iCards_Suit[j];
                iCards_Suit[j] = iCards_Suit[j - 1];
                iCards_Suit[j - 1] = temp;
            }
        }

    for (i = 0; i < 21; i++) {
        flush = true; straight = true; Cards_Shape = 0; categories = 1; iCards_Total[0] = 1;
        for (j = 0; j < 4; j++) {
            if (iCards_Suit[iFull_Permutation[i][j]] != iCards_Suit[iFull_Permutation[i][j + 1]]) flush = false;
            if (iCards_Number[iFull_Permutation[i][j]] != iCards_Number[iFull_Permutation[i][j + 1]] - 1) straight = false;
        }
        if (iCards_Number[iFull_Permutation[i][0]] == 2 && iCards_Number[iFull_Permutation[i][1]] == 3 && iCards_Number[iFull_Permutation[i][2]] == 4 && iCards_Number[iFull_Permutation[i][3]] == 5 && iCards_Number[iFull_Permutation[i][4]] == 14) straight = true;
        if (straight == true) Cards_Shape = 5;
        if (flush == true) Cards_Shape = 4;
        if (flush == true && straight == true) Cards_Shape = 1;
        if (Cards_Shape == 0) {
            for (j = 1; j < 5; j++) {
                if (iCards_Number[iFull_Permutation[i][j]] == iCards_Number[iFull_Permutation[i][j - 1]]) iCards_Total[categories - 1]++;
                else {
                    categories++;
                    iCards_Total[categories - 1] = 1;
                }
            }
            if (categories == 2) {
                if (iCards_Total[0] == 1 || iCards_Total[1] == 1) Cards_Shape = 2;
                else Cards_Shape = 3;
            }
            else if (categories == 3) {
                if (iCards_Total[0] == 3 && iCards_Total[1] == 3 && iCards_Total[2] == 3) Cards_Shape = 6;
                else Cards_Shape = 7;
            }
            else if (categories == 4) Cards_Shape = 8;
            else Cards_Shape = 9;
        }
        if (Cards_Shape < Max_Shape) Max_Shape = Cards_Shape;
    }
    return Max_Shape;
}
//找到最大卡型
void Game::Check_All_Cards(int iCurrent[7], int x) {
    int iCards_Number[7];
    int iCards_Suit[7];
    int iCards_Total[5];
    int a[5];
    int i, j, temp, categories;
    int Cards_Shape, Max_Shape;
    bool flush, straight;
    Max_Shape = 10;
    for (i = 0; i < 7; i++) {
        iCards_Number[i] = iCurrent[i] % 13;
        iCards_Suit[i] = (iCurrent[i] - 1) / 13;
        if (iCards_Number[i] == 1) iCards_Number[i] += 13;
    }
    for (i = 0; i < 6; i++)
        for (j = 6; j > i; j--) {
            if (iCards_Number[j] < iCards_Number[j - 1]) {
                temp = iCurrent[j];
                iCurrent[j] = iCurrent[j - 1];
                iCurrent[j - 1] = temp;
                temp = iCards_Number[j];
                iCards_Number[j] = iCards_Number[j - 1];
                iCards_Number[j - 1] = temp;
                temp = iCards_Suit[j];
                iCards_Suit[j] = iCards_Suit[j - 1];
                iCards_Suit[j - 1] = temp;
            }
        }

    for (i = 0; i < 21; i++) {
        flush = true; straight = true; Cards_Shape = 0; categories = 1; iCards_Total[0] = 1;
        for (j = 0; j < 4; j++) {
            if (iCards_Suit[iFull_Permutation[i][j]] != iCards_Suit[iFull_Permutation[i][j + 1]]) flush = false;
            if (iCards_Number[iFull_Permutation[i][j]] != iCards_Number[iFull_Permutation[i][j + 1]] - 1) straight = false;
        }
        if (iCards_Number[iFull_Permutation[i][0]] == 2 && iCards_Number[iFull_Permutation[i][1]] == 3 && iCards_Number[iFull_Permutation[i][2]] == 4 && iCards_Number[iFull_Permutation[i][3]] == 5 && iCards_Number[iFull_Permutation[i][4]] == 14) straight = true;
        if (straight == true) Cards_Shape = 5;
        if (flush == true) Cards_Shape = 4;
        if (flush == true && straight == true) Cards_Shape = 1;
        if (Cards_Shape == 0) {
            for (j = 1; j < 5; j++) {
                if (iCards_Number[iFull_Permutation[i][j]] == iCards_Number[iFull_Permutation[i][j - 1]]) iCards_Total[categories - 1]++;
                else {
                    categories++;
                    iCards_Total[categories - 1] = 1;
                }
            }
            if (categories == 2) {
                if (iCards_Total[0] == 1 || iCards_Total[1] == 1) Cards_Shape = 2;
                else Cards_Shape = 3;
            }
            else if (categories == 3) {
                if (iCards_Total[0] == 3 && iCards_Total[1] == 3 && iCards_Total[2] == 3) Cards_Shape = 6;
                else Cards_Shape = 7;
            }
            else if (categories == 4) Cards_Shape = 8;
            else Cards_Shape = 9;
        }
        if (Cards_Shape == Max_Shape) {
            for (j = 0; j < 5; j++) a[j] = iCurrent[iFull_Permutation[i][j]];
            if (Player[x].Compare_Cards(a, Cards_Shape) == 1) Player[x].Set_Max_Cards(a);
        }
        else if (Cards_Shape < Max_Shape) {
            for (j = 0; j < 5; j++) a[j] = iCurrent[iFull_Permutation[i][j]];
            Max_Shape = Cards_Shape;
            Player[x].Set_Max_Cards(a);
        }
    }
}
//仅剩一人未放弃
void Game::Calculate_Value() {
    int i;
    for (i = 0; i < 5; i++) if (Player[i].Get_State()) break;
    Player[i].Earn_Cash(iTotal_Cash);
    cout << "其他人都放弃啦" << endl;
    for (i = 0; i < 5; i++) cout << Player[i].Get_Cash() << ' ';
    cout << endl;
}
//四轮结束，计算胜者
void Game::Calculate_The_Game() {
    int i, j, k, x; int a[7]; int temp[5];
    int money;
    int winner[4]; x = -1;
    bool fl = false;
    for (i = 0; i < 5; i++) {
        if (Player[i].Get_State() == true) {
            for (j = 0; j < 5; j++) a[j] = iPublic_Cards[j];
            for (j = 0; j < 5; j++) {
                a[5] = iPlayer_Cards[j * 2]; a[6] = iPlayer_Cards[j * 2 + 1];
                Check_All_Cards(a, i);
        /*		for (j = 0; j < 7; j++) cout << a[j] << ' ';
                cout << endl;*/
            }
            if (fl == false) {
                fl = true;
                x++;
                winner[x] = i;
            }
            else {
                if (Player[i].Fourth_Value() < Player[winner[x]].Fourth_Value()) {
                    x = 0;
                    winner[x] = i;
                }
                else if (Player[i].Fourth_Value() == Player[winner[x]].Fourth_Value()) {
                    for (j = 0; j < 5; j++) temp[j] = Player[i].Get_Max_Cards(j);
                    if (Player[winner[x]].Compare_Cards(temp, Player[winner[x]].Fourth_Value()) == 1) {
                        x = 0;
                        winner[x] = i;
                    }
                    if (Player[winner[x]].Compare_Cards(temp, Player[winner[x]].Fourth_Value()) == 2) {
                        x++;
                        winner[x] = i;
                    }
                }
            }
        }
    }
    cout << "赢家有" << x + 1 << "个" << endl;
    for (i = 0; i < x; i++) Player[winner[i]].Earn_Cash(iTotal_Cash / (x + 1) / 100 * 100);
    Player[winner[x]].Earn_Cash(iTotal_Cash - (iTotal_Cash / (x + 1) / 100 * 100) * x);
    for (i = 0; i < 5; i++) cout << Player[i].Get_Cash() << ' ';
    cout << endl;
}
//第一次下注
void Game::First_Bet() {
    int Checked_Player = 0; int Real_Pay;
    int iPlayer_Bet[5] = { 0, 0, 0, 0, 0 };
    int i = iFirst_Player; int x; int j;
    int bottom = iLowest_Chips;
    int pre_bottom;
    bool Big_Blind = false; bool Small_Blind = false;
    while (1) {
        system("pause");
        if (iCurrent_Players == 1) {
            Calculate_Value();
            return;
        }
        if (Player[i].Get_State() && Player[i].Get_Is_Out()) {
            if (i != 2) {
                if (Small_Blind == false) {
                    Real_Pay = bottom / 2;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    Real_Pay = bottom;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    if (bottom < (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Two_Cards_Value[Player[i].First_Value()] / 100 / 100 * 100) bottom = (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Two_Cards_Value[Player[i].First_Value()] / 100 / 100 * 100;
                    else if (bottom > (Player[i].Get_Cash() + iPlayer_Bet[i]) * iSup_Two_Cards_Value[Player[i].First_Value()] / 100 / 100 * 100 && Player[i].Get_Cash() > 1000 && bottom > iPlayer_Bet[i]) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    if (Player[i].Get_State() == true) {
                        Real_Pay = bottom - iPlayer_Bet[i];
                        if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                        if (Real_Pay == 0) {
                            Checked_Player++;
                            if (Checked_Player == iCurrent_Players) break;
                        }
                        else {
                            Player[i].Pay_Cash(Real_Pay);
                            iTotal_Cash += Real_Pay;
                            iPlayer_Bet[i] += Real_Pay;
                            iPlayer_Bet_Total[i] += Real_Pay;
                            bottom = Max(iPlayer_Bet[i], pre_bottom);
                            pre_bottom = bottom;
                            Checked_Player = 0;
                        }
                    }
                    else {
                        bottom = pre_bottom;
                    }
                }
            }
            else {
                if (Small_Blind == false) {
                    cout << "本次为小盲注，您的投注金额为100，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    cout << "本次为大盲注，您的投注金额为200，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    cout << "请输入你的投注金额：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0 && bottom > iPlayer_Bet[i]) {
                        iCurrent_Players--;
                        Player[i].Fold();
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                        bottom = Max(iPlayer_Bet[i], pre_bottom);
                        pre_bottom = bottom;
                        if (x == 0) Checked_Player++;
                        if (Checked_Player == iCurrent_Players) break;
                    }

                }
            }
        }
        for (j = 0; j < 5; j++) cout << iPlayer_Bet[j] << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) cout << Player[j].Get_Cash() << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) if (Player[j].Get_State() == true) cout << "1 "; else cout << "0 ";
        cout << endl;

        cout << Checked_Player << ' ' << iCurrent_Players << endl;
        i++;
        if (i > 4) i = 0;
    }
    Flop();
}
//翻三张公共牌
void Game::Flop() {
    int i = 0; int x;
    while (i < 3) {
        x = (rand() % 52) + 1;
        if (bCards[x] == false) {
            iPublic_Cards[i] = x;
            bCards[x] = true;
            i++;
            cout << x << ' ';
        }
    }
    for (i = 0; i < 5; i++) if (i != 2) Player[i].Get_Second_Value(Check_Five_Cards(iPlayer_Cards[2 * i], iPlayer_Cards[2 * i + 1], iPublic_Cards[0], iPublic_Cards[1], iPublic_Cards[2]));
    cout << endl;

    for (i = 0; i < 5; i++) cout << Player[i].Second_Value() << ' ';
    cout << endl;

    system("pause");

    Second_Bet();
}
//第二次下注
void Game::Second_Bet() {
    int Checked_Player = 0; int Real_Pay;
    int iPlayer_Bet[5] = { 0, 0, 0, 0, 0 };
    int i = (iFirst_Player + 1) % 5;; int x; int j;
    int bottom = iLowest_Chips;
    int pre_bottom;
    bool Big_Blind = false; bool Small_Blind = false;
    while (1) {
        system("pause");
        if (iCurrent_Players == 1) {
            Calculate_Value();
            return;
        }
        if (Player[i].Get_State() && Player[i].Get_Is_Out()) {
            if (i != 2) {
                if (Small_Blind == false) {
                    Real_Pay = bottom / 2;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    Real_Pay = bottom;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    if (bottom < (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Five_Cards_Value[Player[i].Second_Value()] / 100 / 100 * 100) bottom = (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Five_Cards_Value[Player[i].Second_Value()] / 100 / 100 * 100;
                    else if (bottom > (Player[i].Get_Cash() + iPlayer_Bet[i]) * iSup_Five_Cards_Value[Player[i].Second_Value()] / 100 / 100 * 100 && Player[i].Get_Cash() > 1000 && bottom > iPlayer_Bet[i]) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    if (Player[i].Get_State() == true) {
                        Real_Pay = bottom - iPlayer_Bet[i];
                        if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                        if (Real_Pay == 0) {
                            Checked_Player++;
                            if (Checked_Player == iCurrent_Players) break;
                        }
                        else {
                            Player[i].Pay_Cash(Real_Pay);
                            iTotal_Cash += Real_Pay;
                            iPlayer_Bet[i] += Real_Pay;
                            iPlayer_Bet_Total[i] += Real_Pay;
                            bottom = Max(iPlayer_Bet[i], pre_bottom);
                            pre_bottom = bottom;
                            Checked_Player = 0;
                        }
                    }
                    else {
                        bottom = pre_bottom;
                    }
                }
            }
            else {
                if (Small_Blind == false) {
                    cout << "本次为小盲注，您的投注金额为100，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    cout << "本次为大盲注，您的投注金额为200，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    cout << "请输入你的投注金额：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0 && bottom > iPlayer_Bet[i]) {
                        iCurrent_Players--;
                        Player[i].Fold();
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                        bottom = Max(iPlayer_Bet[i], pre_bottom);
                        pre_bottom = bottom;
                        if (x == 0) Checked_Player++;
                        if (Checked_Player == iCurrent_Players) break;
                    }
                }
            }
        }

        for (j = 0; j < 5; j++) cout << iPlayer_Bet[j] << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) cout << Player[j].Get_Cash() << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) if (Player[j].Get_State() == true) cout << "1 "; else cout << "0 ";
        cout << endl;
        cout << Checked_Player << ' ' << iCurrent_Players << endl;

        i++;
        if (i > 4) i = 0;
    }
    Turn();
}
//翻一张公共牌
void Game::Turn() {
    int i = 3; int x;
    while (i < 4) {
        x = (rand() % 52) + 1;
        if (bCards[x] == false) {
            iPublic_Cards[i] = x;
            bCards[x] = true;
            i++;
            cout << x << endl;
        }
    }
    for (i = 0; i < 5; i++)
        if (i != 2) Player[i].Get_Third_Value(Check_Six_Cards(iPlayer_Cards[2 * i], iPlayer_Cards[2 * i + 1], iPublic_Cards[0], iPublic_Cards[1], iPublic_Cards[2], iPublic_Cards[3]));

    for (i = 0; i < 5; i++) cout << Player[i].Third_Value() << ' ';

    cout << endl;

    system("pause");
    Third_Bet();
}
//第三次下注
void Game::Third_Bet() {
    int Checked_Player = 0; int Real_Pay;
    int iPlayer_Bet[5] = { 0, 0, 0, 0, 0 };
    int i = (iFirst_Player + 2) % 5; int x; int j;
    int bottom = iLowest_Chips;
    int pre_bottom;
    bool Big_Blind = false; bool Small_Blind = false;
    while (1) {
        system("pause");
        if (iCurrent_Players == 1) {
            Calculate_Value();
            return;
        }
        if (Player[i].Get_State() && Player[i].Get_Is_Out()) {
            if (i != 2) {
                if (Small_Blind == false) {
                    Real_Pay = bottom / 2;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    Real_Pay = bottom;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    if (bottom < (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Six_Cards_Value[Player[i].Third_Value()] / 100 / 100 * 100) bottom = (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Six_Cards_Value[Player[i].Third_Value()] / 100 / 100 * 100;
                    else if (bottom > (Player[i].Get_Cash() + iPlayer_Bet[i]) * iSup_Six_Cards_Value[Player[i].Third_Value()] / 100 / 100 * 100 && Player[i].Get_Cash() > 1000 && bottom > iPlayer_Bet[i]) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    if (Player[i].Get_State() == true) {
                        Real_Pay = bottom - iPlayer_Bet[i];
                        if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                        if (Real_Pay == 0) {
                            Checked_Player++;
                            if (Checked_Player == iCurrent_Players) break;
                        }
                        else {
                            Player[i].Pay_Cash(Real_Pay);
                            iTotal_Cash += Real_Pay;
                            iPlayer_Bet[i] += Real_Pay;
                            iPlayer_Bet_Total[i] += Real_Pay;
                            bottom = Max(iPlayer_Bet[i], pre_bottom);
                            pre_bottom = bottom;
                            Checked_Player = 0;
                        }
                    }
                    else {
                        bottom = pre_bottom;
                    }
                }
            }
            else {
                if (Small_Blind == false) {
                    cout << "本次为小盲注，您的投注金额为100，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    cout << "本次为大盲注，您的投注金额为200，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    cout << "请输入你的投注金额：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0 && bottom > iPlayer_Bet[i]) {
                        iCurrent_Players--;
                        Player[i].Fold();
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                        bottom = Max(iPlayer_Bet[i], pre_bottom);
                        pre_bottom = bottom;
                        if (x == 0) Checked_Player++;
                        if (Checked_Player == iCurrent_Players) break;
                    }
                }
            }
        }
        for (j = 0; j < 5; j++) cout << iPlayer_Bet[j] << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) cout << Player[j].Get_Cash() << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) if (Player[j].Get_State() == true) cout << "1 "; else cout << "0 ";
        cout << endl;
        cout << Checked_Player << ' ' << iCurrent_Players << endl;

        i++;
        if (i > 4) i = 0;
    }
    River();
}
//翻一张公共牌
void Game::River() {
    int i = 4; int x; int a[7]; int j;
    while (i < 5) {
        x = (rand() % 52) + 1;
        if (bCards[x] == false) {
            iPublic_Cards[i] = x;
            bCards[x] = true;
            i++;
            cout << x << endl;
        }
    }
    for (i = 0; i < 5; i++) a[i] = iPublic_Cards[i];
    for (i = 0; i < 5; i++) {
        a[5] = iPlayer_Cards[i * 2]; a[6] = iPlayer_Cards[i * 2 + 1];
        Player[i].Get_Fourth_Value(Check_Seven_Cards(a));
        for (j = 0; j < 7; j++) cout << a[j] << ' ';
        cout << endl;
    }

    for (i = 0; i < 5; i++) cout << Player[i].Fourth_Value() << ' ';
    cout << endl;

    system("pause");
    Fourth_Bet();
}
//第四次下注
void Game::Fourth_Bet() {
    int Checked_Player = 0; int Real_Pay;
    int iPlayer_Bet[5] = { 0, 0, 0, 0, 0 };
    int i = (iFirst_Player + 3) % 5; int x; int j;
    int bottom = iLowest_Chips;
    int pre_bottom;
    bool Big_Blind = false; bool Small_Blind = false;
    while (1) {
        system("pause");
        if (iCurrent_Players == 1) {
            Calculate_Value();
            return;
        }
        if (Player[i].Get_State() && Player[i].Get_Is_Out()) {
            if (i != 2) {
                if (Small_Blind == false) {
                    Real_Pay = bottom / 2;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    Real_Pay = bottom;
                    if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                    Player[i].Pay_Cash(Real_Pay);
                    iTotal_Cash += Real_Pay;
                    iPlayer_Bet[i] += Real_Pay;
                    iPlayer_Bet_Total[i] += Real_Pay;
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    if (bottom < (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Seven_Cards_Value[Player[i].Fourth_Value()] / 100 / 100 * 100) bottom = (Player[i].Get_Cash() + iPlayer_Bet[i]) * iInf_Six_Cards_Value[Player[i].Fourth_Value()] / 100 / 100 * 100;
                    else if (bottom > (Player[i].Get_Cash() + iPlayer_Bet[i]) * iSup_Seven_Cards_Value[Player[i].Fourth_Value()] / 100 / 100 * 100 && Player[i].Get_Cash() > 1000 && bottom > iPlayer_Bet[i]) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    if (Player[i].Get_State() == true) {
                        Real_Pay = bottom - iPlayer_Bet[i];
                        if (Real_Pay > Player[i].Get_Cash()) Real_Pay = Player[i].Get_Cash();
                        if (Real_Pay == 0) {
                            Checked_Player++;
                            if (Checked_Player == iCurrent_Players) break;
                        }
                        else {
                            Player[i].Pay_Cash(Real_Pay);
                            iTotal_Cash += Real_Pay;
                            iPlayer_Bet[i] += Real_Pay;
                            iPlayer_Bet_Total[i] += Real_Pay;
                            bottom = Max(iPlayer_Bet[i], pre_bottom);
                            pre_bottom = bottom;
                            Checked_Player = 0;
                        }
                    }
                    else {
                        bottom = pre_bottom;
                    }
                }
            }
            else {
                if (Small_Blind == false) {
                    cout << "本次为小盲注，您的投注金额为100，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Small_Blind = true;
                }
                else if (Big_Blind == false) {
                    cout << "本次为大盲注，您的投注金额为200，请投注：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0) {
                        Player[i].Fold();
                        iCurrent_Players--;
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                    }
                    Big_Blind = true;
                    pre_bottom = bottom;
                }
                else {
                    cout << "请输入你的投注金额：";
                    cin >> x;
                    if (x == 0 && Player[i].Get_Cash() != 0 && bottom > iPlayer_Bet[i]) {
                        iCurrent_Players--;
                        Player[i].Fold();
                    }
                    else {
                        Player[i].Pay_Cash(x);
                        iTotal_Cash += x;
                        iPlayer_Bet[i] += x;
                        iPlayer_Bet_Total[i] += x;
                        bottom = Max(iPlayer_Bet[i], pre_bottom);
                        pre_bottom = bottom;
                        if (x == 0) Checked_Player++;
                        if (Checked_Player == iCurrent_Players) break;
                    }
                }
            }
        }
        for (j = 0; j < 5; j++) cout << iPlayer_Bet[j] << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) cout << Player[j].Get_Cash() << ' ';
        cout << endl;
        for (j = 0; j < 5; j++) if (Player[j].Get_State() == true) cout << "1 "; else cout << "0 ";
        cout << endl;
        cout << Checked_Player << ' ' << iCurrent_Players << endl;
        i++;
        if (i > 4) i = 0;
    }
    Calculate_The_Game();
}

int Game::Get_iPicture(){
    return iPicture;
}


void Game::Set_iPicture(int x){
    iPicture = x;
}

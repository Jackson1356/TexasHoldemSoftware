#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<cstdlib>
#include<ctime>

class Player {
private:
    int iCash;									//个人金额
    int iFirst_Value;							//两张牌的类型
    int iSecond_Value;							//五张牌的类型
    int iThird_Value;							//三张牌的类型
    int iFourth_Value;							//四张牌的类型
    int iMax_Cards[5];							//七张牌时最大的牌
    bool bState;								//是否放弃
    bool bIs_Out;								//是否没有钱而出局
public:
    Player();
    void Clear();
    void Set_Max_Cards(int a[5]);
    int Compare_Cards(int a[5], int x);
    void Get_First_Value(int x);
    void Get_Second_Value(int x);
    void Get_Third_Value(int x);
    void Get_Fourth_Value(int x);
    int Get_Max_Cards(int x);
    int First_Value();
    int Second_Value();
    int Third_Value();
    int Fourth_Value();
    void Pay_Cash(int x);
    void Earn_Cash(int x);
    bool Get_State();
    bool Get_Is_Out();
    void Game_Over();
    int Get_Cash();
    void Fold();
};

#endif // PLAYER_H

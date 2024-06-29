#ifndef GAME_H
#define GAME_H


#include "player.h"
using namespace std;
class Game {
public:
    Game();
    void Clear();
    int Max(int x, int y);
    int Check_Two_Cards(int x, int y);
    void Pre_Flop();
    void First_Bet();
    int Check_Five_Cards(int x, int y, int z, int u, int v);
    void Flop();
    void Second_Bet();
    int Check_Six_Cards(int x, int y, int z, int u, int v, int w);
    void Turn();
    void Third_Bet();
    int Check_Seven_Cards(int iCurrent[7]);
    void Check_All_Cards(int iCurrent[7], int x);
    void River();
    void Fourth_Bet();
    void Calculate_Value();
    void Calculate_The_Game();
private:
    Player Player[5];																		//玩家信息
    int iRounds;																			//第几轮
    int iPublic_Cards[5];																	//卡牌信息
    int iPlayer_Cards[10];																	//玩家底牌信息
    bool bCards[53];																		//卡牌是否被使用																//
    int iLowest_Chips;																		//最低投注
    int iTotal_Cash;																		//当前筹码池总筹码
    int iCurrent_Players;																	//当前仍在局中的玩家
    int iFirst_Player;																		//本轮第一次投注的第一位玩家序号
    int iSup_Two_Cards_Value[8] = { 100, 100, 100, 30, 30, 20, 10, 10 };					//两张卡投注上限
    int iInf_Two_Cards_Value[8] = { 5, 3, 3, 3, 2, 0, 0, 0 };								//两张卡投注下限
    int iCards_Weight[10] = { 0, 2000, 1800, 1600, 1400, 1200, 1000, 500, 200, 0 };			//各牌型权值
    int iWeight[10] = {1350, 1200, 1050, 900, 750, 600, 450, 300, 150, 0 };					//期望分界
    int iSup_Five_Cards_Value[10] = { 100, 100, 100, 100, 40, 40, 25, 15, 10, 0};			//五张卡投注上限
    int iInf_Five_Cards_Value[10] = { 20, 12, 12, 8, 8, 6, 0, 0, 0, 0 };					//五张卡投注下限
    int iSup_Six_Cards_Value[10] = { 100, 100, 100, 100, 40,  40, 25, 15, 10, 0};			//六张卡投注上限
    int iInf_Six_Cards_Value[10] = { 20, 12, 12, 8, 8, 6, 0, 0, 0, 0 };						//六张卡投注下限
    int iSup_Seven_Cards_Value[10] = { 0, 100, 100, 100, 100, 80, 60, 40, 20, 5 };			//七张卡投注上限
    int iInf_Seven_Cards_Value[10] = { 0, 100, 100, 100, 50, 40, 20, 0, 0, 0 };				//七张卡投注下限
    int iPlayer_Bet_Total[5];																//每个人投注总金额
    int iFull_Permutation[21][5] = { { 0, 1, 2, 3, 4 },										//全排列
                                     { 0, 1, 2, 3, 5 },
                                     { 0, 1, 2, 3, 6 },
                                     { 0, 1, 2, 4, 5 },
                                     { 0, 1, 2, 4, 6 },
                                     { 0, 1, 2, 5, 6 },
                                     { 0, 1, 3, 4, 5 },
                                     { 0, 1, 3, 4, 6 },
                                     { 0, 1, 3, 5, 6 },
                                     { 0, 1, 4, 5, 6 },
                                     { 0, 2, 3, 4, 5 },
                                     { 0, 2, 3, 4, 6 },
                                     { 0, 2, 3, 5, 6 },
                                     { 0, 2, 4, 5, 6 },
                                     { 0, 3, 4, 5, 6 },
                                     { 1, 2, 3, 4, 5 },
                                     { 1, 2, 3, 4, 6 },
                                     { 1, 2, 3, 5, 6 },
                                     { 1, 2, 4, 5, 6 },
                                     { 1, 3, 4, 5, 6 },
                                     { 2, 3, 4, 5, 6 }, };

};

#endif // GAME_H

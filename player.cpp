#include "player.h"
Player::Player() {
    iCash = 10000;
    bIs_Out = true;
}
//牌局开始
void Player::Clear() {
    iFirst_Value = 0;
    iSecond_Value = 0;
    iThird_Value = 0;
    iFourth_Value = 0;
    bState = true;
}
void Player::Get_First_Value(int x) {
    iFirst_Value = x;
}
void Player::Set_Max_Cards(int a[5]) {
    int i;
    for (i = 0; i < 5; i++) iMax_Cards[i] = a[i];
}
//比较卡牌
int Player::Compare_Cards(int a[5], int x) {
    int iCards_Number[5];
    int i, temp1, temp2, y;
    int iOwn_Number[5];
    int b1[4], b2[4]; y = 0;
    for (i = 0; i < 5; i++) {
        iCards_Number[i] = a[i] % 13;
        iOwn_Number[i] = iMax_Cards[i] % 13;
        if (iCards_Number[i] == 1) iCards_Number[i] += 13;
        if (iOwn_Number[i] == 1) iOwn_Number[i] += 13;
    }
    if (x == 1 || x == 5) {
        if (iCards_Number[4] == 14 && iCards_Number[0] == 2) temp1 = 1;
        else temp1 = iCards_Number[0];
        if (iOwn_Number[4] == 14 && iOwn_Number[0] == 2) temp2 = 1;
        else temp2 = iOwn_Number[0];
        if (temp1 == temp2) return 2;
        else if (temp1 > temp2) return 1;
        else return 0;
    }
    if (x == 4 || x == 9) {
        for (i = 4; i >= 0; i--) {
            if (iCards_Number[i] == iOwn_Number[i]) continue;
            else if (iCards_Number[i] < iOwn_Number[i]) return 0;
            else return 1;
        }
        return 2;
    }
    if (x == 2 || x == 3 || x == 6) {
        if (iCards_Number[2] > iOwn_Number[2]) return 1;
        else return 0;
    }

    if (x == 8) {
        y = 0;
        for (i = 0; i < 4; i++) if (iCards_Number[i] == iCards_Number[i + 1]) b1[3] = iCards_Number[i];
        for (i = 0; i < 5; i++) if (iCards_Number[i] != b1[3]) b1[y++] = iCards_Number[i];
        y = 0;
        for (i = 0; i < 4; i++) if (iOwn_Number[i] == iOwn_Number[i + 1]) b2[3] = iOwn_Number[i];
        for (i = 0; i < 5; i++) if (iOwn_Number[i] != b2[3]) b2[y++] = iOwn_Number[i];
        for (i = 3; i >= 0; i--) {
            if (b1[i] == b2[i]) continue;
            else if (b1[i] < b2[i]) return 0;
            else return 1;
        }
        return 2;
    }

    if (x == 7) {
        y = 1;
        for (i = 0; i < 4; i++) if (iCards_Number[i] == iCards_Number[i + 1]) b1[y++] = iCards_Number[i];
        for (i = 0; i < 5; i++) if (iCards_Number[i] != b1[1] && iCards_Number[i] != b1[2]) b1[0] = iCards_Number[i];
        y = 1;
        for (i = 0; i < 4; i++) if (iOwn_Number[i] == iOwn_Number[i + 1]) b2[y++] = iOwn_Number[i];
        for (i = 0; i < 5; i++) if (iOwn_Number[i] != b2[1] && iOwn_Number[i] != b2[2]) b2[0] = iOwn_Number[i];
        for (i = 2; i >= 0; i--) {
            if (b1[i] == b2[i]) continue;
            else if (b1[i] < b2[i]) return 0;
            else return 1;
        }
        return 2;
    }
}
int Player::Get_Max_Cards(int x) {
    return iMax_Cards[x];
}
void Player::Get_Second_Value(int x) {
    iSecond_Value = x;
}
void Player::Get_Third_Value(int x) {
    iThird_Value = x;
}
void Player::Get_Fourth_Value(int x) {
    iFourth_Value = x;
}
int Player::First_Value() {
    return iFirst_Value;
}
int Player::Second_Value() {
    return iSecond_Value;
}
int Player::Third_Value() {
    return iThird_Value;
}
int Player::Fourth_Value() {
    return iFourth_Value;
}
void Player::Pay_Cash(int x) {
    iCash -= x;
}
bool Player::Get_State() {
    return bState;
}
int Player::Get_Cash() {
    return iCash;
}
void Player::Fold() {
    bState = false;
}
void Player::Game_Over() {
    bIs_Out = false;
}
bool Player::Get_Is_Out() {
    return bIs_Out;
}
void Player::Earn_Cash(int x) {
    iCash += x;
}

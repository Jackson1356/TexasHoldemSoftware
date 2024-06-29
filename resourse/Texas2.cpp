#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Cards
{
public:
    Cards();
    void Print();
    int iType;       //从1-10表示不同类型
    int aBestCards[5];
};

bool isIn(int t, int a[], int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        if (a[i] == t)
            return 1;
    }
    return 0;
}

bool SpecialCompare(int a, int b)     //扑克中比大小a>b?
{
    if (b != 1)
    {
        if (a == 1)
            return 1;
        else
        {
            if (a > b)
                return 1;
            else
                return 0;
        }
    }
    else
        return 0;
}

bool SpecialCompare_2(int a, int b)     //扑克中比大小a>=b?
{
    if (b != 1)
    {
        if (a == 1)
            return 1;
        else
        {
            if (a >= b)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        if (a == 1)
            return 1;
        else
            return 0;
    }
}

void Exchange(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int a[], int begin, int end)
{
    if (begin > end) return;
    int tmp = a[begin];
    int i = begin;
    int j = end;
    while (i < j)
    {
        while (SpecialCompare_2(a[j],tmp) && j > i)
            j--;
        while (SpecialCompare_2(tmp, a[i]) && j > i)
            i++;
        if (j > i)   
            Exchange(a[j], a[i]);
    }
    Exchange(a[i], a[begin]);
    Sort(a, begin, i - 1); 
    Sort(a, i + 1, end);
}

void Reverse(int a[], int begin, int end)
{
    int t[100] = { 0 };
    for (int i = begin; i <= end; i++)
        t[i - begin] = a[i];
    for (int i = end; i >= begin; i--)
        a[i] = t[end - i];
}

int SelectLargest(int a[], int begin, int end)
{
    int iLargest = a[begin];
    for (int i = begin; i <= end; i++)
        if (SpecialCompare(a[i], iLargest))
            iLargest = a[i];

    return iLargest;
}

void Shift(int a[])  //将七张牌转换为1-13
{
    for (int i = 0; i < 7; i++)
    {
        a[i] = a[i] % 13;
        if (a[i] == 0)
            a[i] = 13;
    }
}

void Copy(int a1[], int a[])//将a数组拷贝到a1中
{
    for (int i = 0; i < 7; i++)
        a1[i] = a[i];
}

//德州扑克判断函数
bool Flush(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    int aColor[4] = { 0 };            //0-红桃 1-方片 2-黑桃 3-梅花
    for (int i = 0; i < 7; i++)        //统计每种花色个数
    {
        if (a[i] < 14)
            aColor[0]++;
        else if (a[i] > 13 && a[i] < 27)
            aColor[1]++;
        else if (a[i] > 26 && a[i] < 40)
            aColor[2]++;
        else
            aColor[3]++;
    }

    for (int i = 0; i < 4; i++)       //如果同一种花色大于4个，即有同花
    {
        if (aColor[i] > 4)
            return 1;
    }
    return 0;
}

int FOAK(int a1[])//返回具体大小
{
    int a[7] = { 0 };
    Copy(a, a1);

    for (int i = 0; i < 7; i++)         //转换为0-12的大小
    {
        a[i] = a[i] % 13;
    }

    int aCount[13] = { 0 };             //标记每个大小出现的数量
    for (int i = 0; i < 7; i++)
    {
        aCount[a[i]]++;
    }

    for (int i = 0; i < 13; i++)
    {
        if (aCount[i] == 4 && i != 0)
            return i;
        else if (aCount[i] == 4 && i == 0)
            return 13;
    }
    return 0;
}

bool FullHouse(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    for (int i = 0; i < 7; i++)         //转换为0-12的大小
    {
        a[i] = a[i] % 13;
    }

    int aCount[13] = { 0 };           //标记每个大小出现的数量
    for (int i = 0; i < 7; i++)
    {
        aCount[a[i]]++;
    }

    int aNum[3] = { 0 };    //记录对子、三条和四张的次数 0-对子 1-三条 2-四张
    for (int i = 0; i < 13; i++)
    {
        if (aCount[i] == 2)
            aNum[0]++;
        else if (aCount[i] == 3)
            aNum[1]++;
        else if (aCount[i] == 4)
            aNum[2]++;
    }
    if (aNum[2] == 0 && aNum[1] > 1)
        return 1;
    else if (aNum[2] == 0 && aNum[1] == 1 && aNum[0] >= 1)
        return 1;
    else
        return 0;
}

int TOAK(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    for (int i = 0; i < 7; i++)         //转换为0-12的大小
    {
        a[i] = a[i] % 13;
    }

    int aCount[13] = { 0 };           //标记每个大小出现的数量
    for (int i = 0; i < 7; i++)
    {
        aCount[a[i]]++;
    }

    int aNum[3] = { 0 };    //记录对子、三条和四张的次数 0-对子 1-三条 2-四张
    for (int i = 0; i < 13; i++)
    {
        if (aCount[i] == 2)
            aNum[0]++;
        else if (aCount[i] == 3)
            aNum[1]++;
        else if (aCount[i] == 4)
            aNum[2]++;
    }

    if (aNum[2] == 0 && aNum[1] == 1 && aNum[0] == 0)
        for (int i = 0;i < 13;i++)
        {
            if (aCount[i] == 3)
            {
                if (i != 0)
                    return i;
                else
                    return 13;
            }                
        }
    else
        return 0;
}

bool TwoPairs(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    for (int i = 0; i < 7; i++)         //转换为0-12的大小
    {
        a[i] = a[i] % 13;
    }

    int aCount[13] = { 0 };           //标记每个大小出现的数量
    for (int i = 0; i < 7; i++)
    {
        aCount[a[i]]++;
    }

    int aNum[3] = { 0 };    //记录对子、三条和四张的次数 0-对子 1-三条 2-四张
    for (int i = 0; i < 13; i++)
    {
        if (aCount[i] == 2)
            aNum[0]++;
        else if (aCount[i] == 3)
            aNum[1]++;
        else if (aCount[i] == 4)
            aNum[2]++;
    }
    if (aNum[2] == 0 && aNum[1] == 0 && aNum[0] > 1)
        return 1;
    else
        return 0;
}

bool OnePair(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    for (int i = 0; i < 7; i++)         //转换为0-12的大小
    {
        a[i] = a[i] % 13;
    }

    int aCount[13] = { 0 };           //标记每个大小出现的数量
    for (int i = 0; i < 7; i++)
    {
        aCount[a[i]]++;
    }

    int aNum[3] = { 0 };    //记录对子、三条和四张的次数 0-对子 1-三条 2-四张
    for (int i = 0; i < 13; i++)
    {
        if (aCount[i] == 2)
            aNum[0]++;
        else if (aCount[i] == 3)
            aNum[1]++;
        else if (aCount[i] == 4)
            aNum[2]++;
    }
    if (aNum[2] == 0 && aNum[1] == 0 && aNum[0] == 1)
        return 1;
    else
        return 0;
}

int Straight(int a1[])        //若有顺子，返回最大的值
{
    int a[7] = { 0 };
    Copy(a, a1);

    if (!FOAK(a) && !FullHouse(a) && !TOAK(a) && !TwoPairs(a) && !OnePair(a))
    {
        Shift(a);
        Sort(a, 0, 6);

        if (a[4] - a[3] > 1)
            return 0;
        else if (a[3] - a[2] > 1)
        {
            if (a[3] == 10 && a[4] == 11 && a[5] == 12 && a[6] == 13 && a[0] == 1)
                return 1;   //10JQKA
            else return 0;
        }
        else if (a[5] - a[4] > 1)
        {
            if (a[1] - a[0] == 1 && a[2] - a[1] == 1 && a[3] - a[2] == 1 && a[4] - a[3] == 1)
                return a[4];
            else
                return 0;
        }
        else if (a[2] - a[1] > 1)
        {
            if (a[6] - a[5] == 1 && a[5] - a[4] == 1 && a[4] - a[3] == 1 && a[3] - a[2] == 1)
                return a[6];
            else
                return 0;
        }
        else if (a[6] - a[5] == 1)
            return a[6];
        else
            return a[5];
    }

    if (TOAK(a) || TwoPairs(a)) //有三张或两对的情况，即有两张重复的牌
    {
        Shift(a);
        Sort(a, 0, 6);

        int aNoRepeat[5] = { 0 };           //用一个新数列存储不重复的五个数
        int count = 1;
        aNoRepeat[0] = a[0];
        for (int i = 1; i < 7; i++)
        {
            if (a[i] != a[i - 1])
            {
                aNoRepeat[count] = a[i];
                count++;
            }
        }

        if (aNoRepeat[4] - aNoRepeat[3] == 1 && aNoRepeat[3] - aNoRepeat[2] == 1 && aNoRepeat[2] - aNoRepeat[1] == 1 && aNoRepeat[1] - aNoRepeat[0] == 1)
            return aNoRepeat[4];
        else
            return 0;
    }

    if (OnePair(a))             // 有一对的情况，即有一张重复的牌
    {
        Shift(a);
        Sort(a, 0, 6);

        int aNoRepeat[6] = { 0 };           //用一个新数列存储不重复的六个数
        int count = 1;
        aNoRepeat[0] = a[0];
        for (int i = 1; i < 7; i++)
        {
            if (!isIn(a[i], aNoRepeat, 0, 5))
            {
                aNoRepeat[count] = a[i];
                count++;
            }
        }

        //前五位是顺子
        if (aNoRepeat[4] - aNoRepeat[3] == 1 && aNoRepeat[3] - aNoRepeat[2] == 1 && aNoRepeat[2] - aNoRepeat[1] == 1 && aNoRepeat[1] - aNoRepeat[0] == 1)
            return aNoRepeat[4];
        //后五位是顺子
        else if (aNoRepeat[4] - aNoRepeat[3] == 1 && aNoRepeat[3] - aNoRepeat[2] == 1 && aNoRepeat[2] - aNoRepeat[1] == 1 && aNoRepeat[5] - aNoRepeat[4] == 1)
            return aNoRepeat[5];
        //后四位是10JQK，第一位是A
        else if (aNoRepeat[0] == 1 && aNoRepeat[4] - aNoRepeat[3] == 1 && aNoRepeat[3] - aNoRepeat[2] == 1 && aNoRepeat[5] - aNoRepeat[4] == 1)
            return 1;
        else
            return 0;
    }

    else
        return 0;
}

int FlushStraight(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    if (!Flush(a) || !Straight(a))
        return 0;

    int aColor[4] = { 0 };            //0-红桃 1-方片 2-黑桃 3-梅花
    for (int i = 0; i < 7; i++)        //统计每种花色个数
    {
        if (a[i] < 14)
            aColor[0]++;
        else if (a[i] > 13 && a[i] < 27)
            aColor[1]++;
        else if (a[i] > 26 && a[i] < 40)
            aColor[2]++;
        else
            aColor[3]++;
    }

    int iColor;                //标记同花的花色
    for (int i = 0; i < 4; i++)
    {
        if (aColor[i] > 4)
            iColor = i;
    }

    if (aColor[iColor] == 7)     //全部都是一种花色
        return Straight(a);

    if (aColor[iColor] == 6)     //六张都是一个花色
    {
        int aFlushCards[6] = { 0 };
        int count = 0;

        for (int i = 0; i < 7; i++)       //将六张同花存储到aFlushCards数组中
        {
            if ((a[i] - 1) / 13 == iColor)
            {
                aFlushCards[count] = a[i];
                count++;
            }
        }
        for (int i = 0; i < 6; i++)         //转换为1-13的大小
        {
            aFlushCards[i] = aFlushCards[i] % 13;
            if (aFlushCards[i] == 0)
                aFlushCards[i] = 13;
        }
        Sort(aFlushCards, 0, 5);

        if (Straight(a) == 1)   //10JQKA
        {
            if (isIn(1, aFlushCards, 0, 5))
            {
                for (int i = 10; i < 14; i++)           //判断10JQK是否in
                    if (!isIn(i, aFlushCards, 0, 5))
                        return 0;
                return 1;
            }
            else
                return 0;
        }
        else
        {
            for (int i = Straight(a); i > (Straight(a) - 5); i--)
                if (!isIn(i, aFlushCards, 0, 5))
                    return 0;
            return Straight(a);
        }
    }

    if (aColor[iColor] == 5)        //五张是一个花色
    {
        int aFlushCards[5] = { 0 };
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if ((a[i] - 1) / 13 == iColor)
            {
                aFlushCards[count] = a[i];
                count++;
            }
        }

        for (int i = 0; i < 5; i++)         //转换为1-13的大小
        {
            aFlushCards[i] = aFlushCards[i] % 13;
            if (aFlushCards[i] == 0)
                aFlushCards[i] = 13;
        }
        Sort(aFlushCards, 0, 4);

        if (aFlushCards[4] - aFlushCards[3] == 1 && aFlushCards[3] - aFlushCards[2] == 1 && aFlushCards[2] - aFlushCards[1] == 1)
        {
            if (aFlushCards[1] - aFlushCards[0] == 1)
                return aFlushCards[4];
            else if (aFlushCards[0] == 1 && aFlushCards[4] == 13)   //10JQKA
                return 1;
            else
                return 0;
        }

        else
            return 0;
    }
}

bool RoyalFlush(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    if (FlushStraight(a) == 1)
    {
        return 1;
    }

    else
        return 0;
}

Cards::Cards()
{
    iType = 0;
    for (int i = 0; i < 5; i++)
        aBestCards[i] = 0;
}

Cards BestCards(int a1[])
{
    int a[7] = { 0 };
    Copy(a, a1);

    Cards cCards;

    if (RoyalFlush(a))
    {
        cCards.iType = 10;          //标记为皇家同花顺

        int iA = 0;                //用于记录RoyalFlush中A的花色，即在1-52中的大小
        if (isIn(1, a1, 0, 6) && isIn(10, a1, 0, 6) && isIn(11, a1, 0, 6))//红桃
            iA = 1;
        else if (isIn(14, a1, 0, 6) && isIn(23, a1, 0, 6) && isIn(24, a1, 0, 6))//方片)
            iA = 14;
        else if (isIn(27, a1, 0, 6) && isIn(36, a1, 0, 6) && isIn(37, a1, 0, 6))//方片)
            iA = 27;
        else
            iA = 40;

        cCards.aBestCards[0] = iA;   //首张为A
        for (int i = 1; i < 5; i++)    //剩下为KQJ10
            cCards.aBestCards[i] = iA+13 - i;

        return cCards;
    }

    if (FlushStraight(a))
    {
        cCards.iType = 9;        //标记为同花顺

        int iA = Straight(a);              //记录顺子最大牌的花色，即在1-52中的值
        if (isIn(iA, a1, 0, 6) && isIn(iA - 1, a1, 0, 6) && isIn(iA - 2, a1, 0, 6))
            iA = Straight(a);
        else if (isIn(iA + 13, a1, 0, 6) && isIn(iA + 12, a1, 0, 6) && isIn(iA + 11, a1, 0, 6))
            iA = Straight(a) + 13;
        else if (isIn(iA + 26, a1, 0, 6) && isIn(iA + 25, a1, 0, 6) && isIn(iA + 24, a1, 0, 6))
            iA = Straight(a) + 26;
        else
            iA = Straight(a) + 39;

        for (int i = 0; i < 5; i++)
            cCards.aBestCards[i] = iA - i;

        return cCards;
    }

    if (FOAK(a))
    {
        int t = FOAK(a);

        cCards.iType = 8;     //标注为四条

        for (int i = 0; i < 4; i++)
            cCards.aBestCards[i] = t + i*13;

        Shift(a);

        for (int i = 0; i < 7; i++)          //消除四条
            if (a[i] == t)
                a[i] = 0;

        int iA = SelectLargest(a, 0, 6);     //寻找剩余牌中的最大
        if (isIn(iA, a1, 0, 6))
            cCards.aBestCards[4] = iA;
        else if (isIn(iA + 13, a1, 0, 6))
            cCards.aBestCards[4] = iA + 13;
        else if (isIn(iA + 26, a1, 0, 6))
            cCards.aBestCards[4] = iA + 26;
        else
            cCards.aBestCards[4] = iA + 39;


        return cCards;
    }

    if (FullHouse(a))
    {
        cCards.iType = 7;        //标记为葫芦

        Shift(a);

        int t = 0;
        int count = 0;           //记录相同数量
        for (int i = 0; i < 7; i++)
        {
            count = 0;
            for (int l = 0; l < 7; l++)
            {
                if (a[l] == a[i])
                    count++;
            }
            if (count == 3 && SpecialCompare(a[i], t))     //找到三张牌中最大的
                t = a[i];
        }

        //找到这三张的花色并以1-52的取值存储在cCards.aBestCards中
        if (isIn(t, a1, 0, 6))
        {
            cCards.aBestCards[0] = t;

            if (isIn(t + 13, a1, 0, 6))
            {
                cCards.aBestCards[1] = t + 13;

                if (isIn(t + 26, a1, 0, 6))
                    cCards.aBestCards[2] = t + 26;
                else
                    cCards.aBestCards[2] = t + 39;
            }
            else
                for (int i = 1; i < 3; i++)
                    cCards.aBestCards[i] = t + (i + 1) * 13;
        }
        else
            for (int i = 0; i < 3; i++)
                cCards.aBestCards[i] = t + (i + 1) * 13;

        for (int i = 0; i < 7; i++)           //将三条改为零，更新剩下的对子
            if (a[i] == t)
                a[i] = 0;

        t = 0;
        count = 0;
        for (int i = 0; i < 7; i++)
        {
            count = 0;
            for (int l = 0; l < 7; l++)
            {
                if (a[l] == a[i])
                    count++;
            }
            if (count >= 2 && SpecialCompare(a[i], t))     //找到两张牌中最大的
                t = a[i];
        }

        count = 3;
        for (int i = 0; i < 4; i++)
        {
            if (isIn(t + i * 13, a1, 0, 6) && !isIn(t + i * 13, cCards.aBestCards, 0, 5))
            {
                cCards.aBestCards[count] = t + i * 13;
                count++;
            }
            if (count == 5)
                break;
        }

        return cCards;
    }

    if (Flush(a))
    {
        cCards.iType = 6;              //标注为同花

        int aColor[4] = { 0 };            //0-红桃 1-方片 2-黑桃 3-梅花
        for (int i = 0; i < 7; i++)        //统计每种花色个数
        {
            if (a[i] < 14)
                aColor[0]++;
            else if (a[i] > 13 && a[i] < 27)
                aColor[1]++;
            else if (a[i] > 26 && a[i] < 40)
                aColor[2]++;
            else
                aColor[3]++;
        }

        int iColor;
        for (int i = 0; i < 4; i++)
            if (aColor[i] > 4)
                iColor = i;                 //标记同花的花色

        int t = 4;                    //记录aBestCards
        for (int i = 6; i > -1; i--)
            if ((a[i] - 1) / 13 == iColor)
            {
                if (a[i] % 13 == 0)
                    cCards.aBestCards[t] = 13;
                else
                    cCards.aBestCards[t] = a[i] % 13;
                t--;
                if (t == -1)
                    break;
            }

        Sort(cCards.aBestCards, 0, 4);
        Reverse(cCards.aBestCards, 0, 4);

        for (int i = 0; i < 5; i++)
            cCards.aBestCards[i] = cCards.aBestCards[i] + 13 * iColor;
        
        return cCards;
        
    }

    if (Straight(a))
    {
        cCards.iType = 5;          //标注为顺子

        if (Straight(a) == 1)     //10JQKA
        {
            for (int t = 0; t < 4; t++)     //找到A的花色并以1-52存储
            {
                if (isIn(1 + t * 13, a1, 0, 6))
                    cCards.aBestCards[0] = 1 + t * 13;
            }
            for (int i = 1; i < 5; i++)
                cCards.aBestCards[i] = 8 + i + cCards.aBestCards[0];
        }

        else
        {
            for (int i = 0; i < 5; i++)
            {
                for (int t = 0; t < 4; t++)
                {
                    if (isIn(Straight(a) + t * 13 - i, a1, 0, 6))
                        cCards.aBestCards[i] = Straight(a) + t * 13 - i;
                }
            }
        }

        return cCards;
    }

    if (TOAK(a))
    {
        cout << TOAK(a) << endl;
        cCards.iType = 4;       //标注为三张

        Shift(a);

        int t = TOAK(a);
        //找到这三张的花色并以1-52的取值存储在cCards.aBestCards中
        if (isIn(t, a1, 0, 6))
        {
            cCards.aBestCards[0] = t;

            if (isIn(t + 13, a1, 0, 6))
            {
                cCards.aBestCards[1] = t + 13;

                if (isIn(t + 26, a1, 0, 6))
                    cCards.aBestCards[2] = t + 26;
                else
                    cCards.aBestCards[2] = t + 39;
            }
            else
                for (int i = 1; i < 3; i++)
                    cCards.aBestCards[i] = t + (i + 1) * 13;
        }
        else
            for (int i = 0; i < 3; i++)
                cCards.aBestCards[i] = t + (i + 1) * 13;

        for (int i = 0; i < 7; i++)           //将三条改为零，更新剩下的两张牌
            if (a[i] == t)
                a[i] = 0;

        int iA= SelectLargest(a, 0, 6);
        for (int tmp = 0; tmp < 4; tmp++)
            if (isIn(iA + tmp * 13, a1, 0, 6))
                cCards.aBestCards[3] = iA + tmp * 13;

        for (int i = 0; i < 7; i++)
            if (a[i] == iA)
                a[i] = 0;

        iA = SelectLargest(a, 0, 6);
        for (int tmp = 0; tmp < 4; tmp++)
            if (isIn(iA + tmp * 13, a1, 0, 6))
                cCards.aBestCards[4] = iA + tmp * 13;

        return cCards;
    }

    if (TwoPairs(a))
    {
        cCards.iType = 3;          //标记为两对

        Shift(a);

        int t = 0;
        int count = 0;              //记录相同数量
        for (int i = 0; i < 7; i++) //寻找到较大的对子
        {
            count = 0;
            for (int l = 0; l < 7; l++)
            {
                if (a[l] == a[i])
                    count++;
            }
            if (count == 2 && SpecialCompare(a[i], t))   //若此牌出现两次且比已知值大
                t = a[i];
        }
        for (int i = 0; i < 2; i++)
        {
            for (int tmp = 0; tmp < 4; tmp++)
                if (isIn(t + tmp * 13, a1, 0, 6) && !isIn(t + tmp * 13, cCards.aBestCards, 0, 5))
                    cCards.aBestCards[i] = t + tmp * 13;
        }

        for (int i = 0; i < 7; i++)         //将大对子改为零，更新剩下的对子＋一张牌
            if (a[i] == t)
                a[i] = 0;

        t = 0;
        count = 0;
        for (int i = 0; i < 7; i++)       //寻找剩下的较大的对子
        {
            count = 0;
            for (int l = 0; l < 7; l++)
            {
                if (a[l] == a[i])
                    count++;
            }
            if (count == 2 && SpecialCompare(a[i], t))
                t = a[i];
        }
        for (int i = 2; i < 4; i++)
        {
            for (int tmp = 0; tmp < 4; tmp++)
                if (isIn(t + tmp * 13, a1, 0, 6))
                    cCards.aBestCards[i] = t + tmp * 13;
        }
        
        for (int i = 0; i < 7; i++)
            if (a[i] == t)
                a[i] = 0;

        int iA = SelectLargest(a, 0, 6);
        for (int tmp = 0;tmp < 4;tmp++)
            if (isIn(iA + tmp * 13, a1, 0, 6) && !isIn(t + tmp * 13, cCards.aBestCards, 0, 5))
                cCards.aBestCards[4] = iA + tmp * 13;

        return cCards;
    }

    if (OnePair(a))
    {
        cCards.iType = 2;         //标记为一对

        Shift(a);

        int t = 0;
        int count = 0;           //记录相同数量
        for (int i = 0; i < 7; i++)
        {
            count = 0;
            for (int l = 0; l < 7; l++)
            {
                if (a[l] == a[i])
                    count++;
            }
            if (count == 2 && SpecialCompare(a[i], t))
                t = a[i];
        }
        for (int i = 0; i < 2; i++)
        {
            for (int tmp = 0; tmp < 4; tmp++)
                if (isIn(t + tmp * 13, a1, 0, 6) && !isIn(t + tmp * 13, cCards.aBestCards, 0, 5))
                    cCards.aBestCards[i] = t + tmp * 13;
        }

        for (int i = 0; i < 7; i++)           //将对子改为零，更新剩下的三张牌
            if (a[i] == t)
                a[i] = 0;

        for (int m = 2; m < 5; m++)         //每次填入最大牌并将其重置为0避免重复
        {
            int iA = SelectLargest(a, 0, 6);
            for (int tmp = 0; tmp < 4;tmp++)
                if (isIn(iA + tmp * 13, a1, 0, 6))
                    cCards.aBestCards[m] = iA + tmp * 13;

            for (int i = 0; i < 7; i++)
                if (a[i] == iA)
                    a[i] = 0;
        }

        return cCards;
    }

    else
    {
        cCards.iType = 1;                 //标记为高牌

        Shift(a);

        for (int m = 0; m < 5; m++)         //每次填入最大牌并将其重置为0避免重复
        {
            int iA = SelectLargest(a, 0, 6);
            for (int tmp = 0; tmp < 4;tmp++)
                if (isIn(iA + tmp * 13, a1, 0, 6))
                    cCards.aBestCards[m] = iA + tmp * 13;

            for (int i = 0; i < 7; i++)
                if (a[i] == iA)
                    a[i] = 0;
        }

        return cCards;
    }
}

void Cards::Print()
{
    cout << "My best cards are: ";
    for (int i = 0; i < 5; i++)
    {

        int a = aBestCards[i] % 13;
        int b = (aBestCards[i] - 1) / 13;

        if (b == 0)
            cout << "红桃";
        else if (b == 1)
            cout << "方片";
        else if (b == 2)
            cout << "黑桃";
        else if (b == 3)
            cout << "梅花";

        if (a == 1)
            cout << "A ";
        else if (a == 0)
            cout << "K ";
        else if (a == 12)
            cout << "Q ";
        else if (a == 11)
            cout << "J ";
        else
            cout << a << " ";
    }
    cout << endl;
    cout << "The type is: ";
    if (iType == 10)
        cout << "Royal Flush" << endl;
    else if (iType == 9)
        cout << "Straight Flush" << endl;
    else if (iType == 8)
        cout << "Four of a Kind" << endl;
    else if (iType == 7)
        cout << "Full House" << endl;
    else if (iType == 6)
        cout << "Flush" << endl;
    else if (iType == 5)
        cout << "Straight" << endl;
    else if (iType == 4)
        cout << "Three of a Kind" << endl;
    else if (iType == 3)
        cout << "Two Pairs" << endl;
    else if (iType == 2)
        cout << "One Pair" << endl;
    else
        cout << "High Cards" << endl;
}

int main()
{
    int aCards[7] = { 0 };
    int t;

    unsigned seed;
    seed = time(0);
    srand(seed);
    
    for (int i = 0; i < 7; i++)
    {
        t = rand() % 52 + 1;
        if (!isIn(t, aCards, 0, 6))
        {
            aCards[i] = t;
        }
    }
    

    cout << "My cards are: ";
    for (int i = 0; i < 7; i++)
    {
        int a = aCards[i] % 13;
        int b = (aCards[i] - 1) / 13;

        if (b == 0)
            cout << "红桃";
        else if (b == 1)
            cout << "方片";
        else if (b == 2)
            cout << "黑桃";
        else if (b == 3)
            cout << "梅花";

        if (a == 1)
            cout << "A ";
        else if (a == 0)
            cout << "K ";
        else if (a == 12)
            cout << "Q ";
        else if (a == 11)
            cout << "J ";
        else
            cout << a << " ";
    }
    cout << endl;

    Cards c1;
    c1 = BestCards(aCards);

    c1.Print();

    cout << endl;
    return 0;
}
#include<stdio.h>
#include<windows.h>  //颜色
#include<string.h>
#include<conio.h>  //通过控制台进行数据输入和数据输出的函数
#include<stdlib.h>
#include<time.h>   //定义时间函数
struct node  //定义四个人物名
{
    char name[20];
} people[4];
int map[100] =
{
    0,0,0,0,0,2,1,0,0,3,0,0,0,2,0,0,0,2,0,0,4,0,0,1,0,4,0,3,0,0,
    0,0,0,2,0,
    0,0,0,2,0,1,0,0,0,0,4,0,0,0,0,2,0,0,0,0,1,0,0,0,0,3,0,0,4,2,
    0,0,0,0,1,
    0,0,4,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,4,0,4,0,0,3,2,0,0,0,0,0
}; //地图的数字代码
int number1, number2;  //玩家1的选择人物序号
int numstep1, numstep2;  //玩家1的选择人物序号
int rand(void);    //伪随机数生成函数
void srand(unsigned int n); //种子函数
void showmap(int map[])   //打印游戏地图
{
    int i, j, k;
    printf("\t\t\t骑 士 飞 行 棋 \n\n");
    printf("'∷'是平地，'¤'是幸运罗盘，'★'是地雷，'■'是暂停，'〓'是时空隧道\n\n");
    for (i = 0; i < 31; i++)
    {
        if (map[i] == 0)
            printf("∷");
        else if (map[i] == 1)
            printf("¤");
        else if (map[i] == 2)
            printf("★");
        else if (map[i] == 3)
            printf("■");
        else if (map[i] == 4)
            printf("〓");
        else if (map[i] == 10)
            printf("Ａ");
        else if (map[i] == 20)
            printf("Ｂ");
        else if (map[i] == 30)
            printf("@@");
    }
    printf("\n");
    for (k = 0; k < 4; k++)
    {
        for (j = 0; j < 30; j++)
        {
            printf("  ");
        }
        if (map[i] == 0)
            printf("∷");
        else if (map[i] == 1)
            printf("¤");
        else if (map[i] == 2)
            printf("★");
        else if (map[i] == 3)
            printf("■");
        else if (map[i] == 4)
            printf("〓");
        else if (map[i] == 10)
            printf("Ａ");
        else if (map[i] == 20)
            printf("Ｂ");
        else if (map[i] == 30)
            printf("@@");
        i++;
        printf("\n");
    }
    for (i = 65; i >= 35; i--)
    {
        if (map[i] == 0)
            printf("∷");
        else if (map[i] == 1)
            printf("¤");
        else if (map[i] == 2)
            printf("★");
        else if (map[i] == 3)
            printf("■");
        else if (map[i] == 4)
            printf("〓");
        else if (map[i] == 10)
            printf("Ａ");
        else if (map[i] == 20)
            printf("Ｂ");
        else if (map[i] == 30)
            printf("@@");
    }
    printf("\n");
    i = 66;
    for (j = 0; j < 3; j++)
    {
        if (map[i] == 0)
            printf("∷");
        else if (map[i] == 1)
            printf("¤");
        else if (map[i] == 2)
            printf("★");
        else if (map[i] == 3)
            printf("■");
        else if (map[i] == 4)
            printf("〓");
        else if (map[i] == 10)
            printf("Ａ");
        else if (map[i] == 20)
            printf("Ｂ");
        else if (map[i] == 30)
            printf("@@");
        i++;
        printf("\n");
    }
    for (i = 69; i < 100; i++)
    {
        if (map[i] == 0)
            printf("∷");
        else if (map[i] == 1)
            printf("¤");
        else if (map[i] == 2)
            printf("★");
        else if (map[i] == 3)
            printf("■");
        else if (map[i] == 4)
            printf("〓");
        else if (map[i] == 10)
            printf("Ａ");
        else if (map[i] == 20)
            printf("Ｂ");
        else if (map[i] == 30)
            printf("@@");
    }
    printf("\n");
}
void cleana(int map[])  //清除地图上的标记A，并还原地图
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (map[i] == 10)
        {
            if (i == 6 || i == 23 || i == 40 || i == 55 || i == 69 || i == 83)  //‘¤’所对应地图上的位置
                map[i] = 1;
            else if (i == 5 || i == 13 || i == 17 || i == 33 || i == 38 || i == 50 || i == 64 || i == 80 || i == 94) //‘★’所对应地图上的位置
                map[i] = 2;
            else if (i == 9 || i == 27 || i == 60 || i == 93)   //‘■’所对应地图上的位置
                map[i] = 3;
            else if (i == 20 || i == 25 || i == 45 || i == 63 || i == 72 || i == 88 || i == 90)    //‘〓’所对应地图上的位置
                map[i] = 4;
            else
                map[i] = 0;
        }
    }
}
void cleanb(int map[])   //清除地图上的标记B，并还原地图
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (map[i] == 20)
        {
            if (i == 6 || i == 23 || i == 40 || i == 55 || i == 69 || i == 83)   //‘¤’所对应地图上的位置
                map[i] = 1;
            else if (i == 5 || i == 13 || i == 17 || i == 33 || i == 38 || i == 50 || i == 64 || i == 80 || i == 94)  //‘★’所对应地图上的位置
                map[i] = 2;
            else if (i == 9 || i == 27 || i == 60 || i == 93)    //‘■’所对应地图上的位置
                map[i] = 3;
            else if (i == 20 || i == 25 || i == 45 || i == 63 || i == 72 || i == 88 || i == 90)   //‘〓’所对应地图上的位置
                map[i] = 4;
            else
                map[i] = 0;
        }
    }
}
void showprocess(int map[])  //游戏进行的过程
{
    int flag1 = 2, flag2 = 2; //控制游戏暂停的标记变量
    numstep1 = 0;   //玩家1的初始位置
    numstep2 = 0;   //玩家2的初始位置
    int numtou;   //每回投掷的骰子数
    int t;        //作为幸运罗盘交换位置时的中间变量
    int number;   //作为输入幸运罗盘选择时的变量
    system("cls");  //清屏
    showmap(map);   //调用函数showmap(map)用来输出地图
    printf("\n");
    while (numstep1 < 100 && numstep2 < 100)  //游戏开始
    {
        system("pause");  //运行时会出现“请按任意键继续 . .
        printf("\n");
        cleana(map);      //清除地图上的标记A
        cleanb(map);      //清除地图上的标记B
        if (flag1 == 2)      //判断是否为暂停
        {
            if (flag2 == 0 || flag2 == 1)
            {
                flag2++;
            }
            srand(time(NULL));   //是设置随机数的种子，以当前时间作为随机数的种子
            numtou = rand() % 6 + 1;   //产生随机数
            numstep1 += numtou;
            Sleep(500);          //暂停0.5秒
            printf("\n玩家1掷出的点数为 %d\n\n", numtou);
            if (numstep1 >= 100)    //步数大于100时跳出循环，游戏结束
            {
                map[99] = 10;      //使地图上的最后一个位置为A
                Sleep(1000);     //暂停1秒
                system("cls");   //清屏
                showmap(map);    //调用函数showmap(map)用来输出地图
                printf("\n\n");
                printf("游戏结束！\n");
                break;
            }
            else
            {
                printf("玩家1%s,你当前的位置为 %d\n", people[number1 - 1].name, numstep1);
                Sleep(800);
                if (map[numstep1 - 1] == 0)      //地图位置上为'∷'
                {
                    map[numstep1 - 1] = 10;
                    if (numstep1 == numstep2)  //判断玩家1，玩家2的位置是否相同
                    {
                        printf("\n玩家2%s被炸飞了!\n", people[number2 - 1].name);
                        numstep2 = 0;
                        printf("玩家2%s,你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                    }
                    if (numstep2 != 0)
                        map[numstep2 - 1] = 20;
                    Sleep(1000);     //暂停1秒
                    system("cls");   //清屏
                    showmap(map);    //打印地图
                    printf("\n");
                }
                else if (map[numstep1 - 1] == 1)    //地图位置上为'¤'，幸运轮盘
                {
                    printf("\n玩家1%s,恭喜你来到幸运罗盘！\n", people[number1 - 1].name);
                    printf("请做出选择:\n");
                    printf("1.和对方交换位置\n2.轰炸对方(炸退六步)\n");
                    scanf("%d", &number);  //输入选择数
                    if (number == 1)         //交换玩家位置
                    {
                        t = numstep1;
                        numstep1 = numstep2;
                        numstep2 = t;
                        printf("玩家1%s,你当前的位置为%d\n", people[number1 - 1].name, numstep1);
                        printf("\n玩家2%s，你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                        if (numstep1 == 0)
                        {
                            map[numstep2 - 1] = 20;
                        }
                        else
                        {
                            map[numstep1 - 1] = 10;
                            map[numstep2 - 1] = 20;
                        }
                        if (numstep1 == numstep2 && numstep1 != 0)
                        {
                            map[numstep1 - 1] = 30;
                        }
                        Sleep(1800);    //暂停1.8秒
                        system("cls");  //清屏
                        showmap(map);   //打印地图
                        printf("\n");
                    }
                    else if (number == 2)   //对方退六步
                    {
                        map[numstep1 - 1] = 10;
                        if (numstep2 >= 6)
                        {
                            numstep2 -= 6;
                        }
                        else numstep2 = 0;
                        printf("玩家2%s,你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                        if (numstep2 != 0)
                        {
                            map[numstep2 - 1] = 20;
                        }
                        if (numstep1 == numstep2 && numstep1 != 0)
                        {
                            map[numstep1 - 1] = 30;
                        }
                        Sleep(1800);      //暂停1.8秒
                        system("cls");    //清屏
                        showmap(map);     //打印地图
                        printf("\n");
                    }
                }
                else if (map[numstep1 - 1] == 2)   //地图位置上为'★'，地雷
                {
                    printf("\nSORRY , 你踩到地雷了  要后退6步●﹏●\n");
                    if (numstep1 >= 6)
                        numstep1 -= 6;
                    else numstep1 = 0;
                    printf("\n玩家1%s,你当前的位置为%d\n", people[number1 - 1].name, numstep1);
                    if (numstep1 == 0 && numstep2 != 0)
                    {
                        map[numstep2 - 1] = 20;
                    }
                    else if (numstep1 != 0 && numstep2 == 0)
                    {
                        map[numstep1 - 1] = 10;
                    }
                    else if (numstep1 != 0 && numstep2 != 0)
                    {
                        map[numstep1 - 1] = 10;
                        map[numstep2 - 1] = 20;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);     //暂停1.8秒
                    system("cls");   //清屏
                    showmap(map);    //打印地图
                    printf("\n");
                }
                else if (map[numstep1 - 1] == 3)      //地图位置上为'■'，暂停一次
                {
                    flag1 = 0;
                    printf("\n~~>_<~~ 要停战一局了！\n");
                    map[numstep1 - 1] = 10;
                    if (numstep2 != 0)
                    {
                        map[numstep2 - 1] = 20;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);      //暂停1.8秒
                    system("cls");    //清屏
                    showmap(map);     //打印地图
                    printf("\n");
                }
                else if (map[numstep1 - 1] == 4)      //地图位置上为'〓'，时空隧道
                {
                    printf("\nOh  My God ,是时空隧道！！ 冲啊^_^\n");
                    numstep1 += 10;
                    if (numstep1 >= 100)
                    {
                        map[99] = 10;
                        Sleep(1000);
                        system("cls");
                        showmap(map);
                        printf("\n\n");
                        printf("游戏结束！\n");
                        break;
                    }
                    printf("\n玩家1%s,你当前的位置为%d\n", people[number1 - 1].name, numstep1);
                    map[numstep1 - 1] = 10;
                    if (numstep2 != 0)
                    {
                        map[numstep2 - 1] = 20;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);      //暂停1.8秒
                    system("cls");    //清屏
                    showmap(map);     //打印地图
                    printf("\n");
                }
            }
        }
        else if (flag1 != 2)    //当玩家1为暂停状态
        {
            flag1++;
        }
        system("pause");        //显示"请按任意键继续....."
        printf("\n");
        cleana(map);            //清除地图上的标记A
        cleanb(map);            //清除地图上的标记B
        if (flag2 == 2)        //判断玩家2是否为暂停状态
        {
            if (flag1 == 0 || flag1 == 1)
            {
                flag1++;
            }
            srand(time(NULL));          //是设置随机数的种子，以当前时间作为随机数的种子
            numtou = rand() % 6 + 1;          //产生随机数
            numstep2 += numtou;
            Sleep(500);                 //暂停0.5秒
            printf("\n玩家2掷出的点数为%d\n\n", numtou);
            if (numstep2 >= 100)           //步数大于100时跳出循环，游戏结束
            {
                map[99] = 20;             //使地图上最后一个位置为B
                Sleep(1000);            //暂停1秒
                system("cls");          //清屏
                showmap(map);           //打印地图
                printf("\n\n");
                printf("游戏结束！\n");
                break;
            }
            else
            {
                printf("玩家2%s,你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                Sleep(1000);              //暂停1秒
                if (map[numstep2 - 1] == 0)    //地图位置上为'∷'
                {
                    map[numstep2 - 1] = 20;
                    if (numstep1 == numstep2)
                    {
                        printf("\n玩家1%s被炸飞了!\n", people[number1 - 1].name);
                        numstep1 = 0;
                        printf("玩家1%s,你当前的位置为%d\n", people[number1 - 1].name, numstep1);
                    }
                    if (numstep1 != 0)
                        map[numstep1 - 1] = 10;
                    Sleep(1000);
                    system("cls");
                    showmap(map);
                    printf("\n");
                }
                else if (map[numstep2 - 1] == 1)    //地图上位置为'¤'，幸运轮盘
                {
                    printf("\n玩家2%s,恭喜你来到幸运罗盘！\n", people[number2 - 1].name);
                    printf("请做出选择:\n");
                    printf("1.和对方交换位置\n2.轰炸对方(炸退六步)\n");
                    scanf("%d", &number);
                    if (number == 1)  //玩家双方交换位置
                    {
                        t = numstep1;
                        numstep1 = numstep2;
                        numstep2 = t;
                        printf("\n玩家1%s,你当前的位置为%d\n", people[number1 - 1].name, numstep1);
                        printf("\n玩家2%s，你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                        if (numstep2 == 0)
                        {
                            map[numstep1 - 1] = 10;
                        }
                        else
                        {
                            map[numstep1 - 1] = 10;
                            map[numstep2 - 1] = 20;
                        }
                        if (numstep1 == numstep2 && numstep1 != 0)
                        {
                            map[numstep1 - 1] = 30;
                        }
                        Sleep(1800);
                        system("cls");
                        showmap(map);
                        printf("\n");
                    }
                    else if (number == 2)   //对方退六步
                    {
                        map[numstep2 - 1] = 20;
                        if (numstep1 >= 6)
                        {
                            numstep1 -= 6;
                        }
                        else numstep1 = 0;
                        printf("玩家1%s,你当前的位置为%d\n", people[number1 - 1].name, numstep1);
                        if (numstep1 != 0)
                        {
                            map[numstep1 - 1] = 10;
                        }
                        if (numstep1 == numstep2 && numstep1 != 0)
                        {
                            map[numstep1 - 1] = 30;
                        }
                        Sleep(1800);
                        system("cls");
                        showmap(map);
                        printf("\n");
                    }
                }
                else if (map[numstep2 - 1] == 2)   //地图上位置为'★',地雷
                {
                    printf("\nSORRY , 你踩到地雷了  要后退6步●﹏●\n");
                    if (numstep2 >= 6)
                        numstep2 -= 6;
                    else numstep2 = 0;
                    printf("\n玩家2%s,你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                    if (numstep2 == 0 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 10;
                    }
                    else if (numstep2 != 0 && numstep1 == 0)
                    {
                        map[numstep2 - 1] = 20;
                    }
                    else if (numstep1 != 0 && numstep2 != 0)
                    {
                        map[numstep1 - 1] = 10;
                        map[numstep2 - 1] = 20;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);
                    system("cls");
                    showmap(map);
                    printf("\n");
                }
                else if (map[numstep2 - 1] == 3)    //地图位置上为'■'，暂停一次
                {
                    flag2 = 0;
                    printf("\n~~>_<~~ 要停战一局了\n");
                    map[numstep2 - 1] = 20;
                    if (numstep1 != 0)
                    {
                        map[numstep1 - 1] = 10;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);
                    system("cls");
                    showmap(map);
                    printf("\n");
                }
                else if (map[numstep2 - 1] == 4)         //地图位置上为'〓'，时空隧道
                {
                    printf("\nOh  My God ,是时空隧道！！ 冲啊^_^\n");
                    numstep2 += 10;
                    if (numstep1 >= 100)    //步数大于100，跳出循环
                    {
                        map[99] = 10;
                        Sleep(1000);
                        system("cls");
                        showmap(map);
                        printf("\n\n");
                        printf("游戏结束！\n");
                        break;
                    }
                    printf("\n玩家2%s,你当前的位置为%d\n", people[number2 - 1].name, numstep2);
                    map[numstep2 - 1] = 20;
                    if (numstep1 != 0)
                    {
                        map[numstep1 - 1] = 10;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);
                    system("cls");
                    showmap(map);
                    printf("\n");
                }
            }
        }
        else if (flag2 != 0)
        {
            flag2++;
        }
    }
    if (numstep1 > numstep2)  //判断玩家的输赢
        printf("\n恭喜玩家1%s，你赢了！!!!\n", people[number1 - 1].name);
    else printf("\n恭喜玩家2%s，你赢了！!!!\n", people[number2 - 1].name);
}
void showready()
{
    int i;
    printf("地图载入中——");
    for (i = 0; i < 15; i++)
    {
        printf(".");
        Sleep(100);
    }
    system("cls");
    showmap(map);
    printf("\n\n");
    printf("玩家1%s,你当前的位置为 0\n", people[number1 - 1].name);
    printf("玩家2%s,你当前的位置为 0\n\n", people[number2 - 1].name);
    system("pause");
    printf("\n游戏开始！\n请玩家1先开始掷骰子\n");
    Sleep(1000);
    showprocess(map);
}
void showstart()   //展示游戏开始界面
{
    int i;
    int choose;
    system("color 71");
    printf("**************************************************\n");
    printf("//                                              //\n");
    printf("//                                              //\n");
    printf("//               骑 士 飞 行 棋                 //\n");
    printf("//                                              //\n");
    printf("//                                              //\n");
    printf("**************************************************\n");
    for (i = 0; i < 5; i++)
    {
        printf("\n");
    }
    printf("~~~~~~~~~~~两 人 对 战~~~~~~~~~~~\n\n");
    printf("请选择角色：");
    strcpy(people[0].name, "戴高乐");
    strcpy(people[1].name, "艾森豪威尔");
    strcpy(people[2].name, "麦克阿瑟");
    strcpy(people[3].name, "巴顿");
    for (i = 1; i <= 4; i++)
    {
        printf("%d.%s ", i, people[i - 1].name);
    }
    printf("\n");
    printf("请玩家1选择角色（选择序号）：");
    scanf("%d", &number1);
    printf("请玩家2选择角色（选择序号）：");
    scanf("%d", &number2);
    printf("\n\n");
    printf("1.直接进行游戏   2.阅读游戏规则\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        showready();
    }
    else if (choose == 2)   //展示游戏规则
    {
        system("cls");
        printf("\n~~~~~~~~~~~~~~~~~~~游戏规则如下~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("1.两个玩家轮流掷骰子，如果上轮走到暂停关卡，停掷一次\n\n");
        printf("2.若玩家走到幸运轮盘，则和对方交换位置或者对方后退6步\n\n");
        printf("3.若玩家走到某格，而对方也在此格，则对方退回原点\n\n");
        printf("4.若遇到地雷后退6步\n\n");
        printf("5.若遇到暂停则此玩家下一回合停止掷骰子\n\n");
        printf("6.若遇到时空隧道再前进10步\n\n");
        printf("注意：棋盘上的关卡只在骑兵第一次移动遇到时有效\n\n");
        Sleep(1800);
        system("pause");
        printf("\n");
        showready();
    }
}
int main()
{
    char str[10];
    showstart();
    printf("\n是否再来一局？请选择： (Yes/No)\n");   //判断是否再来一局
    scanf("%s", str);
    if (strcmp(str, "Yes") == 0)
    {
        system("cls");
        cleana(map);
        cleanb(map);
        showstart();
    }
    if (strcmp(str, "No") == 0)
        return 0;
}
#include<stdio.h>
#include<windows.h>  //��ɫ
#include<string.h>
#include<conio.h>  //ͨ������̨���������������������ĺ���
#include<stdlib.h>
#include<time.h>   //����ʱ�亯��
struct node  //�����ĸ�������
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
}; //��ͼ�����ִ���
int number1, number2;  //���1��ѡ���������
int numstep1, numstep2;  //���1��ѡ���������
int rand(void);    //α��������ɺ���
void srand(unsigned int n); //���Ӻ���
void showmap(int map[])   //��ӡ��Ϸ��ͼ
{
    int i, j, k;
    printf("\t\t\t�� ʿ �� �� �� \n\n");
    printf("'��'��ƽ�أ�'��'���������̣�'��'�ǵ��ף�'��'����ͣ��'��'��ʱ�����\n\n");
    for (i = 0; i < 31; i++)
    {
        if (map[i] == 0)
            printf("��");
        else if (map[i] == 1)
            printf("��");
        else if (map[i] == 2)
            printf("��");
        else if (map[i] == 3)
            printf("��");
        else if (map[i] == 4)
            printf("��");
        else if (map[i] == 10)
            printf("��");
        else if (map[i] == 20)
            printf("��");
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
            printf("��");
        else if (map[i] == 1)
            printf("��");
        else if (map[i] == 2)
            printf("��");
        else if (map[i] == 3)
            printf("��");
        else if (map[i] == 4)
            printf("��");
        else if (map[i] == 10)
            printf("��");
        else if (map[i] == 20)
            printf("��");
        else if (map[i] == 30)
            printf("@@");
        i++;
        printf("\n");
    }
    for (i = 65; i >= 35; i--)
    {
        if (map[i] == 0)
            printf("��");
        else if (map[i] == 1)
            printf("��");
        else if (map[i] == 2)
            printf("��");
        else if (map[i] == 3)
            printf("��");
        else if (map[i] == 4)
            printf("��");
        else if (map[i] == 10)
            printf("��");
        else if (map[i] == 20)
            printf("��");
        else if (map[i] == 30)
            printf("@@");
    }
    printf("\n");
    i = 66;
    for (j = 0; j < 3; j++)
    {
        if (map[i] == 0)
            printf("��");
        else if (map[i] == 1)
            printf("��");
        else if (map[i] == 2)
            printf("��");
        else if (map[i] == 3)
            printf("��");
        else if (map[i] == 4)
            printf("��");
        else if (map[i] == 10)
            printf("��");
        else if (map[i] == 20)
            printf("��");
        else if (map[i] == 30)
            printf("@@");
        i++;
        printf("\n");
    }
    for (i = 69; i < 100; i++)
    {
        if (map[i] == 0)
            printf("��");
        else if (map[i] == 1)
            printf("��");
        else if (map[i] == 2)
            printf("��");
        else if (map[i] == 3)
            printf("��");
        else if (map[i] == 4)
            printf("��");
        else if (map[i] == 10)
            printf("��");
        else if (map[i] == 20)
            printf("��");
        else if (map[i] == 30)
            printf("@@");
    }
    printf("\n");
}
void cleana(int map[])  //�����ͼ�ϵı��A������ԭ��ͼ
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (map[i] == 10)
        {
            if (i == 6 || i == 23 || i == 40 || i == 55 || i == 69 || i == 83)  //���衯����Ӧ��ͼ�ϵ�λ��
                map[i] = 1;
            else if (i == 5 || i == 13 || i == 17 || i == 33 || i == 38 || i == 50 || i == 64 || i == 80 || i == 94) //�������Ӧ��ͼ�ϵ�λ��
                map[i] = 2;
            else if (i == 9 || i == 27 || i == 60 || i == 93)   //����������Ӧ��ͼ�ϵ�λ��
                map[i] = 3;
            else if (i == 20 || i == 25 || i == 45 || i == 63 || i == 72 || i == 88 || i == 90)    //����������Ӧ��ͼ�ϵ�λ��
                map[i] = 4;
            else
                map[i] = 0;
        }
    }
}
void cleanb(int map[])   //�����ͼ�ϵı��B������ԭ��ͼ
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (map[i] == 20)
        {
            if (i == 6 || i == 23 || i == 40 || i == 55 || i == 69 || i == 83)   //���衯����Ӧ��ͼ�ϵ�λ��
                map[i] = 1;
            else if (i == 5 || i == 13 || i == 17 || i == 33 || i == 38 || i == 50 || i == 64 || i == 80 || i == 94)  //�������Ӧ��ͼ�ϵ�λ��
                map[i] = 2;
            else if (i == 9 || i == 27 || i == 60 || i == 93)    //����������Ӧ��ͼ�ϵ�λ��
                map[i] = 3;
            else if (i == 20 || i == 25 || i == 45 || i == 63 || i == 72 || i == 88 || i == 90)   //����������Ӧ��ͼ�ϵ�λ��
                map[i] = 4;
            else
                map[i] = 0;
        }
    }
}
void showprocess(int map[])  //��Ϸ���еĹ���
{
    int flag1 = 2, flag2 = 2; //������Ϸ��ͣ�ı�Ǳ���
    numstep1 = 0;   //���1�ĳ�ʼλ��
    numstep2 = 0;   //���2�ĳ�ʼλ��
    int numtou;   //ÿ��Ͷ����������
    int t;        //��Ϊ�������̽���λ��ʱ���м����
    int number;   //��Ϊ������������ѡ��ʱ�ı���
    system("cls");  //����
    showmap(map);   //���ú���showmap(map)���������ͼ
    printf("\n");
    while (numstep1 < 100 && numstep2 < 100)  //��Ϸ��ʼ
    {
        system("pause");  //����ʱ����֡��밴��������� . .
        printf("\n");
        cleana(map);      //�����ͼ�ϵı��A
        cleanb(map);      //�����ͼ�ϵı��B
        if (flag1 == 2)      //�ж��Ƿ�Ϊ��ͣ
        {
            if (flag2 == 0 || flag2 == 1)
            {
                flag2++;
            }
            srand(time(NULL));   //����������������ӣ��Ե�ǰʱ����Ϊ�����������
            numtou = rand() % 6 + 1;   //���������
            numstep1 += numtou;
            Sleep(500);          //��ͣ0.5��
            printf("\n���1�����ĵ���Ϊ %d\n\n", numtou);
            if (numstep1 >= 100)    //��������100ʱ����ѭ������Ϸ����
            {
                map[99] = 10;      //ʹ��ͼ�ϵ����һ��λ��ΪA
                Sleep(1000);     //��ͣ1��
                system("cls");   //����
                showmap(map);    //���ú���showmap(map)���������ͼ
                printf("\n\n");
                printf("��Ϸ������\n");
                break;
            }
            else
            {
                printf("���1%s,�㵱ǰ��λ��Ϊ %d\n", people[number1 - 1].name, numstep1);
                Sleep(800);
                if (map[numstep1 - 1] == 0)      //��ͼλ����Ϊ'��'
                {
                    map[numstep1 - 1] = 10;
                    if (numstep1 == numstep2)  //�ж����1�����2��λ���Ƿ���ͬ
                    {
                        printf("\n���2%s��ը����!\n", people[number2 - 1].name);
                        numstep2 = 0;
                        printf("���2%s,�㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
                    }
                    if (numstep2 != 0)
                        map[numstep2 - 1] = 20;
                    Sleep(1000);     //��ͣ1��
                    system("cls");   //����
                    showmap(map);    //��ӡ��ͼ
                    printf("\n");
                }
                else if (map[numstep1 - 1] == 1)    //��ͼλ����Ϊ'��'����������
                {
                    printf("\n���1%s,��ϲ�������������̣�\n", people[number1 - 1].name);
                    printf("������ѡ��:\n");
                    printf("1.�ͶԷ�����λ��\n2.��ը�Է�(ը������)\n");
                    scanf("%d", &number);  //����ѡ����
                    if (number == 1)         //�������λ��
                    {
                        t = numstep1;
                        numstep1 = numstep2;
                        numstep2 = t;
                        printf("���1%s,�㵱ǰ��λ��Ϊ%d\n", people[number1 - 1].name, numstep1);
                        printf("\n���2%s���㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
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
                        Sleep(1800);    //��ͣ1.8��
                        system("cls");  //����
                        showmap(map);   //��ӡ��ͼ
                        printf("\n");
                    }
                    else if (number == 2)   //�Է�������
                    {
                        map[numstep1 - 1] = 10;
                        if (numstep2 >= 6)
                        {
                            numstep2 -= 6;
                        }
                        else numstep2 = 0;
                        printf("���2%s,�㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
                        if (numstep2 != 0)
                        {
                            map[numstep2 - 1] = 20;
                        }
                        if (numstep1 == numstep2 && numstep1 != 0)
                        {
                            map[numstep1 - 1] = 30;
                        }
                        Sleep(1800);      //��ͣ1.8��
                        system("cls");    //����
                        showmap(map);     //��ӡ��ͼ
                        printf("\n");
                    }
                }
                else if (map[numstep1 - 1] == 2)   //��ͼλ����Ϊ'��'������
                {
                    printf("\nSORRY , ��ȵ�������  Ҫ����6����n��\n");
                    if (numstep1 >= 6)
                        numstep1 -= 6;
                    else numstep1 = 0;
                    printf("\n���1%s,�㵱ǰ��λ��Ϊ%d\n", people[number1 - 1].name, numstep1);
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
                    Sleep(1800);     //��ͣ1.8��
                    system("cls");   //����
                    showmap(map);    //��ӡ��ͼ
                    printf("\n");
                }
                else if (map[numstep1 - 1] == 3)      //��ͼλ����Ϊ'��'����ͣһ��
                {
                    flag1 = 0;
                    printf("\n~~>_<~~ Ҫͣսһ���ˣ�\n");
                    map[numstep1 - 1] = 10;
                    if (numstep2 != 0)
                    {
                        map[numstep2 - 1] = 20;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);      //��ͣ1.8��
                    system("cls");    //����
                    showmap(map);     //��ӡ��ͼ
                    printf("\n");
                }
                else if (map[numstep1 - 1] == 4)      //��ͼλ����Ϊ'��'��ʱ�����
                {
                    printf("\nOh  My God ,��ʱ��������� �尡^_^\n");
                    numstep1 += 10;
                    if (numstep1 >= 100)
                    {
                        map[99] = 10;
                        Sleep(1000);
                        system("cls");
                        showmap(map);
                        printf("\n\n");
                        printf("��Ϸ������\n");
                        break;
                    }
                    printf("\n���1%s,�㵱ǰ��λ��Ϊ%d\n", people[number1 - 1].name, numstep1);
                    map[numstep1 - 1] = 10;
                    if (numstep2 != 0)
                    {
                        map[numstep2 - 1] = 20;
                    }
                    if (numstep1 == numstep2 && numstep1 != 0)
                    {
                        map[numstep1 - 1] = 30;
                    }
                    Sleep(1800);      //��ͣ1.8��
                    system("cls");    //����
                    showmap(map);     //��ӡ��ͼ
                    printf("\n");
                }
            }
        }
        else if (flag1 != 2)    //�����1Ϊ��ͣ״̬
        {
            flag1++;
        }
        system("pause");        //��ʾ"�밴���������....."
        printf("\n");
        cleana(map);            //�����ͼ�ϵı��A
        cleanb(map);            //�����ͼ�ϵı��B
        if (flag2 == 2)        //�ж����2�Ƿ�Ϊ��ͣ״̬
        {
            if (flag1 == 0 || flag1 == 1)
            {
                flag1++;
            }
            srand(time(NULL));          //����������������ӣ��Ե�ǰʱ����Ϊ�����������
            numtou = rand() % 6 + 1;          //���������
            numstep2 += numtou;
            Sleep(500);                 //��ͣ0.5��
            printf("\n���2�����ĵ���Ϊ%d\n\n", numtou);
            if (numstep2 >= 100)           //��������100ʱ����ѭ������Ϸ����
            {
                map[99] = 20;             //ʹ��ͼ�����һ��λ��ΪB
                Sleep(1000);            //��ͣ1��
                system("cls");          //����
                showmap(map);           //��ӡ��ͼ
                printf("\n\n");
                printf("��Ϸ������\n");
                break;
            }
            else
            {
                printf("���2%s,�㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
                Sleep(1000);              //��ͣ1��
                if (map[numstep2 - 1] == 0)    //��ͼλ����Ϊ'��'
                {
                    map[numstep2 - 1] = 20;
                    if (numstep1 == numstep2)
                    {
                        printf("\n���1%s��ը����!\n", people[number1 - 1].name);
                        numstep1 = 0;
                        printf("���1%s,�㵱ǰ��λ��Ϊ%d\n", people[number1 - 1].name, numstep1);
                    }
                    if (numstep1 != 0)
                        map[numstep1 - 1] = 10;
                    Sleep(1000);
                    system("cls");
                    showmap(map);
                    printf("\n");
                }
                else if (map[numstep2 - 1] == 1)    //��ͼ��λ��Ϊ'��'����������
                {
                    printf("\n���2%s,��ϲ�������������̣�\n", people[number2 - 1].name);
                    printf("������ѡ��:\n");
                    printf("1.�ͶԷ�����λ��\n2.��ը�Է�(ը������)\n");
                    scanf("%d", &number);
                    if (number == 1)  //���˫������λ��
                    {
                        t = numstep1;
                        numstep1 = numstep2;
                        numstep2 = t;
                        printf("\n���1%s,�㵱ǰ��λ��Ϊ%d\n", people[number1 - 1].name, numstep1);
                        printf("\n���2%s���㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
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
                    else if (number == 2)   //�Է�������
                    {
                        map[numstep2 - 1] = 20;
                        if (numstep1 >= 6)
                        {
                            numstep1 -= 6;
                        }
                        else numstep1 = 0;
                        printf("���1%s,�㵱ǰ��λ��Ϊ%d\n", people[number1 - 1].name, numstep1);
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
                else if (map[numstep2 - 1] == 2)   //��ͼ��λ��Ϊ'��',����
                {
                    printf("\nSORRY , ��ȵ�������  Ҫ����6����n��\n");
                    if (numstep2 >= 6)
                        numstep2 -= 6;
                    else numstep2 = 0;
                    printf("\n���2%s,�㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
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
                else if (map[numstep2 - 1] == 3)    //��ͼλ����Ϊ'��'����ͣһ��
                {
                    flag2 = 0;
                    printf("\n~~>_<~~ Ҫͣսһ����\n");
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
                else if (map[numstep2 - 1] == 4)         //��ͼλ����Ϊ'��'��ʱ�����
                {
                    printf("\nOh  My God ,��ʱ��������� �尡^_^\n");
                    numstep2 += 10;
                    if (numstep1 >= 100)    //��������100������ѭ��
                    {
                        map[99] = 10;
                        Sleep(1000);
                        system("cls");
                        showmap(map);
                        printf("\n\n");
                        printf("��Ϸ������\n");
                        break;
                    }
                    printf("\n���2%s,�㵱ǰ��λ��Ϊ%d\n", people[number2 - 1].name, numstep2);
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
    if (numstep1 > numstep2)  //�ж���ҵ���Ӯ
        printf("\n��ϲ���1%s����Ӯ�ˣ�!!!\n", people[number1 - 1].name);
    else printf("\n��ϲ���2%s����Ӯ�ˣ�!!!\n", people[number2 - 1].name);
}
void showready()
{
    int i;
    printf("��ͼ�����С���");
    for (i = 0; i < 15; i++)
    {
        printf(".");
        Sleep(100);
    }
    system("cls");
    showmap(map);
    printf("\n\n");
    printf("���1%s,�㵱ǰ��λ��Ϊ 0\n", people[number1 - 1].name);
    printf("���2%s,�㵱ǰ��λ��Ϊ 0\n\n", people[number2 - 1].name);
    system("pause");
    printf("\n��Ϸ��ʼ��\n�����1�ȿ�ʼ������\n");
    Sleep(1000);
    showprocess(map);
}
void showstart()   //չʾ��Ϸ��ʼ����
{
    int i;
    int choose;
    system("color 71");
    printf("**************************************************\n");
    printf("//                                              //\n");
    printf("//                                              //\n");
    printf("//               �� ʿ �� �� ��                 //\n");
    printf("//                                              //\n");
    printf("//                                              //\n");
    printf("**************************************************\n");
    for (i = 0; i < 5; i++)
    {
        printf("\n");
    }
    printf("~~~~~~~~~~~�� �� �� ս~~~~~~~~~~~\n\n");
    printf("��ѡ���ɫ��");
    strcpy(people[0].name, "������");
    strcpy(people[1].name, "��ɭ������");
    strcpy(people[2].name, "��˰�ɪ");
    strcpy(people[3].name, "�Ͷ�");
    for (i = 1; i <= 4; i++)
    {
        printf("%d.%s ", i, people[i - 1].name);
    }
    printf("\n");
    printf("�����1ѡ���ɫ��ѡ����ţ���");
    scanf("%d", &number1);
    printf("�����2ѡ���ɫ��ѡ����ţ���");
    scanf("%d", &number2);
    printf("\n\n");
    printf("1.ֱ�ӽ�����Ϸ   2.�Ķ���Ϸ����\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        showready();
    }
    else if (choose == 2)   //չʾ��Ϸ����
    {
        system("cls");
        printf("\n~~~~~~~~~~~~~~~~~~~��Ϸ��������~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("1.����������������ӣ���������ߵ���ͣ�ؿ���ͣ��һ��\n\n");
        printf("2.������ߵ��������̣���ͶԷ�����λ�û��߶Է�����6��\n\n");
        printf("3.������ߵ�ĳ�񣬶��Է�Ҳ�ڴ˸���Է��˻�ԭ��\n\n");
        printf("4.���������׺���6��\n\n");
        printf("5.��������ͣ��������һ�غ�ֹͣ������\n\n");
        printf("6.������ʱ�������ǰ��10��\n\n");
        printf("ע�⣺�����ϵĹؿ�ֻ�������һ���ƶ�����ʱ��Ч\n\n");
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
    printf("\n�Ƿ�����һ�֣���ѡ�� (Yes/No)\n");   //�ж��Ƿ�����һ��
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
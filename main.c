#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>


int polezap(char pole[][4]);
int vvodp(char pole[][4], int *n, int *m);
int hodkomp1(char pole[][4], int *n, int *m);
int hodkomp2(char pole[][4], int *n, int *m);
int checkwin(char pole[][4], int *n, int *m, int *w);
int exitfunc();
int polezap2(char pole[][4], int *n, int *m);

int main()
{
    char pole[3][4]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    setlocale(LC_ALL, "Rus");
    printf("Игра крестики-нолики\n");
    printf("Пользователь - крестики\n");
    printf("Компьютер - нолики\n");
    printf("\n\n");
    printf("Пример номеров ячеек игрового поля\n");

    printf("|-1-|-2-|-3-|\n");
    printf("|-4-|-5-|-6-|\n");
    printf("|-7-|-8-|-9-|\n");
    printf("\n\n");

int n=3, m=3, w=0;
int err,err1,err2,err3,err4;

err=vvodp(pole, &n, &m);
if (err==0)  err1=hodkomp1(pole, &n, &m);
else return err;

if (err1==0) err=vvodp(pole, &n, &m);
else return err1;

if (err==0) err1=hodkomp2(pole, &n, &m);
else return err;

if (err1==0)  err=vvodp(pole, &n, &m);
else return err1;

if (err==0)  err3=checkwin(pole, &n, &m, &w);
else return err;

if (w==1)
{
    if (err3==0) err2=hodkomp2(pole, &n, &m);
    else return err3;
    if (err2==0) err3=checkwin(pole, &n, &m, &w);
    else return err2;
}

if (w==2)
{
    if (err3==0) err=vvodp(pole, &n, &m);
    else return err3;
    if (err==0) err3=checkwin(pole, &n, &m, &w);
    else return err;
}

if (w==3)
{
    if (err3==0) err2=hodkomp2(pole, &n, &m);
    else return err3;
    if (err2==0) err3=checkwin(pole, &n, &m, &w);
    else return err2;
}

if (w==4)
{
    if (err3==0) err=vvodp(pole, &n, &m);
    else return err3;
    if (err==0) err3=checkwin(pole, &n, &m, &w);
    else return err;
}

if (err3==0) err4=exitfunc(pole,&n, &m);
else return err3;
if (err4!=0) return err4;

return 0;
}


int polezap(char pole[][4])
{
    if (pole==NULL) {printf("Ошибка вывода поля"); return 1;}
    system("cls");
    printf("Игровое поле\n\n");
    printf("|-%c-|-%c-|-%c-|\n", pole[0][0],pole[0][1], pole[0][2]);
    printf("|-%c-|-%c-|-%c-|\n", pole[1][0],pole[1][1], pole[1][2]);
    printf("|-%c-|-%c-|-%c-|\n\n", pole[2][0],pole[2][1], pole[2][2]);
    return 0;
}

int vvodp(char pole[][4], int *n, int *m)
{
    if (pole==NULL) {printf("Ошибка вывода поля"); return 1;}
    if (n==NULL) {printf ("Ошибка второго аргумента функции"); return 2;}
    if (m==NULL) {printf ("Ошибка третьего аргумента функции"); return 3;}
    int ch1=0, cell;
    char p;
    size_t i, j;
    printf("Введите число от 1 до 9\n");
    if ((scanf("%d", &cell)!=1) || (cell==0)) {printf("Ошибка ввода\n"); return 4;}
    if ((cell>=1)&&(cell<=9))
        {
            p=cell+'0';
            for (i=0; i<*n; i++)
                {
                    for (j=0; j<*m; j++)
                    {
                        if (pole[i][j]==p) {pole[i][j]='X'; ch1=1;}
                    }
                }
            if (ch1 > 0) {polezap(pole);}
            else {printf ("Вы выбрали занятую ячейку\n"); vvodp(pole, n, m);}
        }
    else {printf("Введено неверное значение\n"); vvodp(pole, n, m);}
    return 0;
}

int hodkomp1(char pole[][4], int *n, int *m)
{
    char number[5]={'1','3','7','9'};
    size_t i, j;
    int col, ch2=0;
    if (pole==NULL) {printf("Ошибка поля"); return 1;}
    if (n==NULL) {printf ("Ошибка второго аргумента функции"); return 2;}
    if (m==NULL) {printf ("Ошибка третьего аргумента функции"); return 3;}
    if (pole[1][1]=='X')
    {
        srand (time (NULL));
        col=rand()%4;
        for (i=0; i<*n;i++)
        {
            for (j=0; j<*m;j++)
            {
                if (pole[i][j]==number[col]) {pole[i][j]='0';ch2=1;}
            }
        }
        polezap(pole);
    }
    else if (((pole[0][0]=='X') || (pole[0][2]=='X') ||(pole[2][0]=='X') || (pole[2][2]=='X'))&& ch2==0)
        {
            if (pole[0][0]=='X'){ pole[2][2]='0'; ch2=1; polezap(pole);}
            else if (pole[0][2]=='X'){ pole[2][0]='0'; ch2=1; polezap(pole);}
            else if (pole[2][0]=='X'){ pole[0][2]='0'; ch2=1; polezap(pole);}
            else if (pole[2][2]=='X'){pole[0][0]='0' ; ch2=1; polezap(pole);}
        }
    else if (((pole[0][1]=='X')||(pole[1][0]=='X')||(pole[1][2]=='X')||(pole[2][1]=='X'))&& (ch2==0))
    {pole[1][1]='0'; ch2=1; polezap(pole);}
    if (ch2==0) {printf ("Ошибка хода компьютера"); return 4;}
    return 0;}


int hodkomp2(char pole[][4], int *n, int *m)
{
    char d59[2]={'5','9'};
    char d19[2]={'1','9'};
    char d15[2]={'1','5'};
    char d57[2]={'5','7'};
    char d37[2]={'3','7'};
    char d35[2]={'3','5'};
    int k=0, ch3=0;
    size_t i, j;

    if (pole==NULL) {printf("Ошибка поля"); return 1;}
    if (n==NULL) {printf ("Ошибка второго аргумента функции"); return 2;}
    if (m==NULL) {printf ("Ошибка третьего аргумента функции"); return 3;}

    for (i=0; i<*n; i++)
    {
        if ((pole[0][i]=='0') && (pole[1][i]=='0') && (pole[2][i]!='X') && (pole[2][i]!='0') && (k==0)) {pole[2][i]='0'; k=1; polezap(pole);}
        if ((pole[0][i]=='0') && (pole[1][i]!='X') && (pole[1][i]!='0') && (pole[2][i]=='0') && (k==0)) {pole[1][i]='0'; k=1; polezap(pole);}
        if ((pole[0][i]!='0') && (pole[0][i]!='X') && (pole[1][i]=='0') && (pole[2][i]=='0') && (k==0)) {pole[0][i]='0'; k=1; polezap(pole);}
    }

    for (i=0; i<*n; i++)
    {
        if ((pole[i][0]=='0') && (pole[i][1]=='0') && (pole[i][2]!='X') && (pole[i][2]!='0') && (k==0)) {pole[i][2]='0'; k=1; polezap(pole);}
        if ((pole[i][0]!='0') && (pole[i][0]!='X') && (pole[i][1]=='0') && (pole[i][2]=='0') && (k==0)) {pole[i][0]='0'; k=1; polezap(pole);}
        if ((pole[i][0]=='0') && (pole[i][1]!='0') && (pole[i][1]!='X') && (pole[i][2]=='0') && (k==0)) {pole[i][1]='0'; k=1; polezap(pole);}
    }

    if ((pole[0][0]=='0') && (pole[1][1]=='0') && (pole[2][2]!='X') && (pole[2][2]!='0') && (k==0)) {pole[2][2]='0'; k=1; polezap(pole);}
    if ((pole[0][0]=='0') && (pole[1][1]!='X') && (pole[1][1]!='0') && (pole[2][2]=='0') && (k==0)) {pole[1][1]='0'; k=1; polezap(pole);}
    if ((pole[0][0]!='0') && (pole[0][0]!='X') && (pole[1][1]=='0') && (pole[2][2]=='0') && (k==0)) {pole[0][0]='0'; k=1; polezap(pole);}
    if ((pole[0][2]=='0') && (pole[1][1]=='0') && (pole[2][0]!='X') && (pole[2][0]!='0') && (k==0)) {pole[2][0]='0'; k=1; polezap(pole);}
    if ((pole[0][2]!='0') && (pole[0][2]!='X') && (pole[1][1]=='0') && (pole[2][0]=='0') && (k==0)) {pole[0][2]='0'; k=1; polezap(pole);}
    if ((pole[0][2]=='0') && (pole[1][1]!='0') && (pole[1][1]!='X') && (pole[2][0]=='0') && (k==0)) {pole[1][1]='0'; k=1; polezap(pole);}

    for (i=0; i<*n; i++)
    {
        if ((pole[0][0]=='X') && (pole[1][1]=='X') && (pole[2][2]!='X') && (pole[2][2]!='0') && (k==0)) {pole[2][2]='0'; k=1; polezap(pole);}
        if ((pole[0][0]=='X') && (pole[1][1]!='X') && (pole[1][1]!='0') && (pole[2][2]=='X') && (k==0)) {pole[1][1]='0'; k=1; polezap(pole);}
        if ((pole[0][0]!='0') && (pole[0][0]!='X') && (pole[1][1]=='X') && (pole[2][2]=='X') && (k==0)) {pole[0][0]='0'; k=1; polezap(pole);}
    }

    for (i=0; i<*n; i++)
    {
        if ((pole[0][2]=='X') && (pole[1][1]=='X') && (pole[2][0]!='X') && (pole[2][0]!='0') && (k==0)) {pole[2][0]='0'; k=1; polezap(pole);}
        if ((pole[0][2]!='0') && (pole[0][2]!='X') && (pole[1][1]=='X') && (pole[2][0]=='X') && (k==0)) {pole[0][2]='0'; k=1; polezap(pole);}
        if ((pole[0][2]=='X') && (pole[1][1]!='0') && (pole[1][1]!='X') && (pole[2][0]=='X') && (k==0)) {pole[1][1]='0'; k=1; polezap(pole);}
    }
    if (k==0)
    {
        for (i=0; i<*n; i++)
        {
            if (pole[0][i]=='X' && pole[1][i]=='X' && (pole[2][i]!='0'&& pole[2][i]!='X') && k==0 ) {pole[2][i]='0'; k=1; polezap(pole);}
            if ((pole[0][i]!='0' && pole[0][i]!='X') && pole[1][i]=='X' && pole[2][i]=='X' && k==0) {pole[0][i]='0'; k=1; polezap(pole);}
            if (pole[0][i]=='X' && (pole[1][i]!='0' && pole[1][i]!='X') && pole[2][i]=='X' && k==0) {pole[1][i]='0'; k=1; polezap(pole);}
        }

        for (i=0; i<*n; i++)
        {
            if (pole[i][0]=='X' && pole[i][1]=='X' && (pole[i][2]!='0' && pole[i][2]!='X') && k==0) {pole[i][2]='0'; k=1; polezap(pole);}
            if ((pole[i][0]!='0' && pole[i][0]!='X') && pole[i][1]=='X' && pole[i][2]=='X' && k==0) {pole[i][0]='0'; k=1; polezap(pole);}
            if (pole[i][0]=='X' && (pole[i][1]!='0' && pole[i][1]!='X') && pole[i][2]=='X' && k==0) {pole[i][1]='0'; k=1; polezap(pole);}
        }
    }

    if (k==0)
    {
        for (i=0; i<*n; i++)
        {
          if ((pole[0][i]=='0') && (pole[1][i]!='0') && (pole[1][i]!='X') && (pole[2][i]!='0')&& (pole[2][i]!='X') && (k==0)) {pole[2][i]='0'; k=1; polezap(pole);}
          if ((pole[0][i]!='0') && (pole[0][i]!='X') && (pole[1][i]=='0') && (pole[2][i]!='0') && (pole[2][i]!='X') && (k==0)) {pole[0][i]='0'; k=1; polezap(pole);}
          if ((pole[0][i]!='0') && (pole[0][i]!='X') && (pole[1][i]!='0') && (pole[1][i]!='X') && (pole[2][i]=='0') && (k==0)) {pole[1][i]='0'; k=1; polezap(pole);}
        }

         for (i=0; i<*n; i++)
         {
            if (pole[i][0]=='0' && (pole[i][1]!='0' && pole[i][1]!='X') && (pole[i][2]!='0' && pole[i][2]!='X') && k==0) {pole[i][2]='0'; k=1; polezap(pole);}
            if ((pole[i][0]!='0' && pole[i][0]!='X') && pole[i][1]=='0' && (pole[i][2]!='0' && pole[i][2]!='X') && k==0) {pole[i][0]='0'; k=1; polezap(pole);}
            if ((pole[i][0]!='0' && pole[i][0]!='X') && (pole[i][1]!='0' && pole[i][1]!='X') && pole[i][2]=='X' && k==0) {pole[i][1]='0'; k=1; polezap(pole);}
         }
    }

    if (k==0)
    {
        if (pole[0][0]=='0'&& (pole[1][1]!='0' && pole[1][1]!='X') && (pole[2][2]!='0' && pole[2][2]!='X') && ch3==0)
        {
            srand (time (NULL));
            for (i=0; i<*n;i++)
            {
                for (j=0; j<*m;j++)
                {
                    if (pole[i][j]==d59[rand()%2]) {pole[i][j]='0';ch3=1;}
                }
            }
            polezap(pole);
        }

        else if ((pole[0][0]!='0' && pole[0][0]!='X')&& pole[1][1]=='0' && (pole[2][2]!='0' && pole[2][2]!='X') && ch3==0)
        {
            srand (time (NULL));
            for (i=0; i<*n;i++)
            {
                for (j=0; j<*m;j++)
                {
                    if (pole[i][j]==d19[rand()%2]) {pole[i][j]='0';ch3=1;}
                }
            }
            polezap(pole);
        }

        else if ((pole[0][0]!='0' && pole[0][0]!='X')&& (pole[1][1]!='0' && pole[1][1]!='X') && pole[2][2]=='0' && ch3==0)
        {
            srand (time (NULL));
            for (i=0; i<*n;i++)
            {
                for (j=0; j<*m;j++)
                {
                    if (pole[i][j]==d15[rand()%2]) {pole[i][j]='0';ch3=1;}
                }
            }
            polezap(pole);
        }

        else if (pole[0][2]=='0'&& (pole[1][1]!='0' && pole[1][1]!='X') && (pole[2][0]!='0' && pole[2][0]!='X') && ch3==0)
        {
            srand (time (NULL));
            for (i=0; i<*n;i++)
            {
                for (j=0; j<*m;j++)
                {
                    if (pole[i][j]==d57[rand()%2]) {pole[i][j]='0';ch3=1;}
                }
            }
            polezap(pole);

        }

        else if ((pole[0][2]!='0' && pole[0][2]!='X') && pole[1][1]=='0' && (pole[2][0]!='0' && pole[2][0]!='X') && ch3==0)
        {
            srand (time (NULL));
            for (i=0; i<*n;i++)
            {
                for (j=0; j<*m;j++)
                {
                    if (pole[i][j]==d37[rand()%2])  {pole[i][j]='0';ch3=1;}
                }
            }
            polezap(pole);

        }

        else if ((pole[0][2]!='0' && pole[0][2]!='X') && (pole[1][1]!='0' && pole[1][1]!='X') && pole[2][0]=='0' && ch3==0)
        {
            srand (time (NULL));
            for (i=0; i<*n;i++)
            {
                for (j=0; j<*m;j++)
                {
                    if (pole[i][j]==d35[rand()%2]) {pole[i][j]='0';ch3=1;}
                }
            }
            polezap(pole);

        }
    }

    if (k==0)
    {
        if (pole[0][0]!='X' && pole[0][0]!='0' && ch3==0) {pole[0][0]='0'; ch3=1; polezap(pole);}
        if (pole[0][1]!='X' && pole[0][1]!='0' && ch3==0) {pole[0][1]='0'; ch3=1; polezap(pole);}
        if (pole[0][2]!='X' && pole[0][2]!='0' && ch3==0) {pole[0][2]='0'; ch3=1; polezap(pole);}
        if (pole[1][0]!='X' && pole[1][0]!='0' && ch3==0) {pole[1][0]='0'; ch3=1; polezap(pole);}
        if (pole[1][1]!='X' && pole[1][1]!='0' && ch3==0) {pole[1][1]='0'; ch3=1; polezap(pole);}
        if (pole[1][2]!='X' && pole[1][2]!='0' && ch3==0) {pole[1][2]='0'; ch3=1; polezap(pole);}
        if (pole[2][0]!='X' && pole[2][0]!='0' && ch3==0) {pole[2][0]='0'; ch3=1; polezap(pole);}
        if (pole[2][1]!='X' && pole[2][1]!='0' && ch3==0) {pole[2][1]='0'; ch3=1; polezap(pole);}
        if (pole[2][2]!='X' && pole[2][2]!='0' && ch3==0) {pole[2][2]='0'; ch3=1; polezap(pole);}
    }

    if ((k==0) && (ch3==0)) {printf("Ошибка хода компьютера"); return 4;}
    return 0;
}

int checkwin(char pole[][4], int *n, int *m, int *w)
{
    size_t i;
    int win=0;
    if (pole==NULL) {printf("Ошибка поля"); return 1;}
    if (n==NULL) {printf ("Ошибка второго аргумента функции"); return 2;}
    if (m==NULL) {printf ("Ошибка третьего аргумента функции"); return 3;}
    if (w==NULL) {printf("Ошибка четвертого аргумента функции"); return 4;}
    if ((pole[0][0]==pole[1][1]) && (pole[1][1]==pole[2][2]) && (pole[0][0]=='X') && (win==0)) {printf("Вы победили!\n"); win=1; }
    else if ((pole[0][0]==pole[1][1]) && (pole[1][1]==pole[2][2]) && (pole[0][0]=='0') && (win==0)) {printf("Победил компьютер!\n"); win=1;}
    else if ((pole[0][2]==pole[1][1]) && (pole[1][1]==pole[2][0]) && (pole[0][2]=='X') && (win==0)) {printf("Вы победили!\n"); win=1; }
    else if ((pole[0][2]==pole[1][1]) && (pole[1][1]==pole[2][0]) && (pole[0][2]=='0') && (win==0)) {printf("Победил компьютер!\n"); win=1;}

    if (win==0)
    {
        for (i=0;i<*n;i++)
        {
            if ((pole[i][0]==pole[i][1]) && (pole[i][1]==pole[i][2]) && (pole[i][0]=='X') && (win==0)) { printf("Вы победили!\n"); win=1; }
            else if ((pole[i][0]==pole[i][1]) && (pole[i][1]==pole[i][2]) && (pole[i][0]=='0') &&(win==0)) { printf("Победил компьютер!\n"); win=1;}
        }
    }
    if (win==0)
    {
        for (i=0;i<*n;i++)
        {
            if ((pole[0][i]==pole[1][i]) && (pole[1][i]==pole[2][i]) && (pole[0][i]=='X') &&(win==0)) { printf("Вы победили!\n"); win=1;}
            else if ((pole[0][i]==pole[1][i]) && (pole[1][i]==pole[2][i]) && (pole[0][i]=='0') && (win==0)) { printf("Победил компьютер!\n"); win=1;} }
        }

    if (win==0) (*w)++;
    if ((*w)==0) {printf("Ошибка проверки на победу"); return 5;}
    if ((*w)==5) printf("Ничья\n");
    return 0;}

int exitfunc(char pole[][4], int *n, int *m)
{
    int ex=0;
    if (pole==NULL) {printf("Ошибка поля"); return 1;}
    if (n==NULL) {printf ("Ошибка второго аргумента функции"); return 2;}
    if (m==NULL) {printf ("Ошибка третьего аргумента функции"); return 3;}
    printf("Хотите сыграть ещё раз?\n");
    printf("1-да\n2-нет\n");
    scanf("%d", &ex);
    if ((ex==1) || (ex==2))
    {
        if (ex==1)
        {
            system("cls");
            polezap2(pole, n, m);
            main();
        }
        if (ex==2) {printf("Спасибо за игру!"); return 0;}
    }
    else {printf("Ошибка ввода");return 4;}
    return 0;
}

int polezap2(char pole[][4],int *n, int *m)
{
    if (pole==NULL) {printf("Ошибка поля"); return 1;}
    if (n==NULL) {printf ("Ошибка второго аргумента функции"); return 2;}
    if (m==NULL) {printf ("Ошибка третьего аргумента функции"); return 3;}
    int f=0;
    size_t i,j;
    for (i=0; i<*n; i++)
    {
        for (j=0; j<*m; j++)
        {
            f++;
            pole[i][j]=f+'0';
        }
    }
    if (f==0) {printf ("Ошибка заполнения поля"); return 4;}
    return 0;
}

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

char a[9][5][5];
int winner[3][3];
int curboard=4;

void initialise()

{

    int i,j,t,k=49;

    for(t=0;t<9;t++)

    {

        k=49;

        for(i=0;i<5;i++)

        {

            for(j=0;j<5;j++)

            {

                if((j%2!=0)&&(i%2==0))

                    a[t][i][j]='|';

                else if((i%2!=0)&&(j%2==0))

                    a[t][i][j]='-';

                else if(i%2!=0&&j%2!=0)

                    a[t][i][j]='-';

                else

                {

                    a[t][i][j]=k;

                    k++;

                }

            }

        }

    }

    k=49;

    for(i=0;i<3;i++)

    {

        for(j=0;j<3;j++)

            winner[i][j]=k++;

    }

}

void print()

{

    int i,j,t,k,h;

    system("cls");

    printf("\n");

    for(t=0;t<3;t++)

    {

        for(i=0;i<5;i++)

        {

            printf("\n ");

            for(k=3*t;k<3*(t+1);k++)

            {

                if(k>3*t)

                    printf("    |    ");

                else

                    printf("         ");

                for(j=0;j<5;j++)

                {

                    if(k==curboard)

                        printf("%c ",a[k][i][j]);

                    else

                    {

                        if(a[k][i][j]>=48&&a[k][i][j]<=57)

                            printf("  ");

                        else

                            printf("%c ",a[k][i][j]);

                    }

                }

            }

        }

        if(t!=2)

            printf("\n         ------------------------------------------------        ");

        else

            printf("\n                                                                 ");

        for(h=0;h<3;h++)

        {

            if(winner[t][h]>48&&winner[t][h]<=57)

                printf("_     ");

            else

                printf("%c     ",winner[t][h]);

        }

    }

}

int boardfull()

{
    int checkboard = curboard ;
    int i,j;

    for(i=0;i<5;i+=2)

    {

        for(j=0;j<5;j=j+2)

        {

            if(a[checkboard][i][j]>48&&a[checkboard][i][j]<58)

                return 0;

        }

    }

    return 1;

}

void move(char test,int num)

{

    int i,j;

    for(i=0;i<5;i+=2)

    {

        for(j=0;j<5;j+=2)

        {

            if(a[curboard][i][j]==48+num)

                a[curboard][i][j]=test;

        }

    }



}

int won(char test)

{

    int i,j,counter1,counter2,counter3,counter4;

    for(i=0;i<5;i+=2)

    {

        counter1=0;counter2=0;counter3=0,counter4=0;

        for(j=0;j<5;j+=2)

        {

            if(a[curboard][i][j]==test)

                counter1++;

            if(a[curboard][j][i]==test)

                counter2++;

            if(a[curboard][j][j]==test)

                counter3++;

            if(a[curboard][j][4-j]==test)

                counter4++;



        }

        if(counter1==3||counter2==3||counter3==3||counter4==3)

            return 1;

    }

    return 0;

}

void put(char test)

{

    int i,j;

    for(i=0;i<3;i++)

    {

        for(j=0;j<3;j++)

        {

            if(winner[i][j]==49+curboard)

                winner[i][j]=test;

        }

    }

}

int check(char test)

{

    int i,j,counter1,counter2,counter3,counter4;

    for(i=0;i<3;i+=1)

    {

        counter1=0;counter2=0;counter3=0,counter4=0;

        for(j=0;j<3;j+=1)

        {

            if(winner[i][j]==test)

                counter1++;

            if(winner[j][i]==test)

                counter2++;

            if(winner[j][j]==test)

                counter3++;

            if(winner[j][4-j]==test)

                counter4++;



        }

        if(counter1==3||counter2==3||counter3==3||counter4==3)

            return 1;

    }

    return 0;

}

int main()

{

    int i,j,num=0,breaker=0,ch=0;

    char a='O',b='X';

    initialise();

    while(1)

    {

        breaker=0;

        print();

        if(boardfull()==1||won(a)==1||won(b)==1)

        {

            printf("\n  PLAYER A(O) ENTER THE BOARD NUMBER TO MOVE TO  : ");

            scanf("%d",&ch);

            curboard=ch-1;

        }

        print();

        printf("\n\n             PLAYER A(O) ENTER THE NUMBER : ");

        scanf("%d",&num);

        move(a,num);

        if(won(a)==1)

            put(a);

        else if(boardfull()==1)

            put('d');

        curboard=num-1;

        if(check(a)==1)

        {

            print();

            printf("\n PLAYER A(O) WON THE GAME!!!!!!!!!!!!!!!!!!!!!!!");

            break;

        }

        if(boardfull()==1||won(a)==1||won(b)==1)

        {

            printf("\n  PLAYER B(X) ENTER THE BOARD NUMBER TO MOVE TO  : ");

            scanf("%d",&ch);

            curboard=ch-1;

        }

        print();

        printf("\n\n             PLAYER B(X) ENTER THE NUMBER : ");

        scanf("%d",&num);

        move(b,num);

        if(won(b)==1)

            put(b);

        else if(boardfull()==1)

            put('d');

        curboard=num-1;

        if(check(b)==1)

        {

            print();

            printf("\n PLAYER B(X) WON THE GAME!!!!!!!!!!!!!!!!!!!!!!!");

            break;

        }

    }

    getch();

    return 0;

}
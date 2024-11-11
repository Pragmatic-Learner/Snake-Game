#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#define charEmpty '_'
#define charBody 'O'
#define head '@'
#define minPos 1
char keyPress;
int livePos[2] = {minPos,minPos}, snakeLen = 10, snakeLen_X, snakeLen_Y;
void clrsrn(), snakeHori(int posX, int posY), snakeVerti(int posX, int posY), snakeHori_2_Verti(int posX, int posY), printSnake();
int main()
{
    snakeLen_X = snakeLen, snakeLen_Y = 1; livePos[1] = 9;
    //if lenX > lenY then snakeHori else snakeVerti
    printSnake();
    while(1)
    {
        keyPress = getch();
        while(!kbhit())
        {
            switch (keyPress)
            {
            case 'D':case 'd':case 'M':
                livePos[0] += 1;
                break;
            case 'S':case 's':case 'P':
                if (snakeLen_X == 1) {++livePos[1];}
                else {snakeLen_X -= 1; snakeLen_Y += 1; livePos[0] += 1; livePos[1] += 1;}
                break;
            case 'W':case 'w':case 'H':
                if (snakeLen_X == 1) {--livePos[1];}
                else {snakeLen_X -= 1; snakeLen_Y += 1; livePos[0] -= 1; livePos[1] -= 1;}
                break;
            case 'A':case 'a':case 'K':
                livePos[0] -= 1;
                break;
            case 'X':case 'x':
                return 0;
            default:
                break;
            }
            usleep(100000);
            printSnake();
        }
    }
    return 0;
}


void clrsrn(){printf("\e[1;1H\e[2J");}


void snakeHori(int posX, int posY)
{
    for(int printenter=minPos; printenter<posY; ++printenter)
    {
        printf("%d\n", printenter);
        if(printenter == 8){printf("%d", printenter+1);}
    }
    for(int printSpace=minPos; printSpace<posX; ++printSpace)
    {
        printf("%c", charEmpty);
    }
    for(int printSnake=1; printSnake<(snakeLen); ++printSnake)
    {
        printf("%c", charBody);
    }
}


void snakeVerti(int posX, int posY)
{
    int printSpace, printEnter, printSnake;
    for(printSpace=minPos; printSpace<posY-snakeLen+1; ++printSpace)
    {
        printf("%c\n", charEmpty);
    }
    for(printSnake=1; printSnake<(snakeLen); ++printSnake)
    {
        for(printSpace=minPos; printSpace<posX+snakeLen_X-1; ++printSpace)
        {
            printf("%c", charEmpty);
        }
        printf("%c\n", charBody);
    }
    for(printSpace=minPos; printSpace<posX+snakeLen_X-1; ++printSpace)
    {
        printf("%c", charEmpty);
    }
}


void snakeHori_2_Verti(int posX, int posY)
{
    int printSpace, printEnter, printSnake;
    for (printEnter = minPos; printEnter < (posX-snakeLen_Y); printEnter++)
    {
        printf("\n");
    }
    
    for(printSpace = minPos; printSpace < posX; ++printSpace)
    {
        printf("%c", charEmpty);
    }
    for(printSnake = posX; printSnake < (posX+snakeLen_X); ++printSnake)
    {
        printf("%c", charBody);
    }
    printf("\n");
    for(printSnake = 1; printSnake < (snakeLen_Y-1); ++printSnake)
    {
        for(printSpace = minPos; printSpace< (posX+snakeLen_X-1); ++printSpace)
        {
            printf("%c", charEmpty);
        }
        printf("%c\n", charBody);
    }
    for(printSpace = minPos; printSpace < (posX+snakeLen_X-1); ++printSpace)
    {
        printf("%c", charEmpty);
    }
}


void printSnake()
{
    clrsrn();
    if (snakeLen_Y == 1)
    {
        snakeHori(livePos[0], livePos[1]);
    }else if (snakeLen_X == 1)
    {
        snakeVerti(livePos[0], livePos[1]);
    }else
    {
        snakeHori_2_Verti(livePos[0], livePos[1]);
    }
    printf("%c", head);
    //printf("%c", head);
    printf("\nLivePos_X     = %i | LivePos_Y    = %i", livePos[0], livePos[1]);
    printf("\nsnakeLen_X    = %i | snakeLen_Y   = %i", snakeLen_X, snakeLen_Y);
    printf("\nsnakeLength   = %i", snakeLen);
}
#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include <iostream>
using namespace std;
enum Direction {STOP,UP,DOWN,LEFT,RIGHT};
class Snake
{
public:
    int x,y;
    int xTail[100],yTail[100],nTail;
    int xPrev,yPrev;
    int xPrev2,yPrev2;
    Direction Dir;
    Snake (int width,int height)
    {
        x = width/2;
        y = height/2;
        Dir = STOP;
        nTail =1;
    }
    void Move()
    {
        switch (Dir)
        {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
        }
    }

    void MakeTail()
    {
        xPrev = xTail[0];
        yPrev = yTail[0];
        xTail[0] = x;
        yTail[0] = y;
        for (int l=1;l<nTail;l++)
        {
            xPrev2 = xTail[l];
            yPrev2 = yTail[l];
            xTail[l] = xPrev;
            yTail[l] = yPrev;
            xPrev = xPrev2;
            yPrev = yPrev2;
        }
    }

};

#endif // SNAKE_H_INCLUDED

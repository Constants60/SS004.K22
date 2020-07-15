#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED
#include "Bait.h"
#include "Snake.h"
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std; 
int _score = 0;
class GameFunction
{
private:
    int Speed = 200;
    int w,h;
    bool GameOver;
    int Score;
    Snake *snake;
    Moi *bait;
    int xPrevSnake,yPrevSnake;
    int xPrevTail[100],yPrevTail[100];
    int xPrevBait,yPrevBait;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    GameFunction (int width,int height)
    {
        w = width;
        h = height;
        snake = new Snake(width,height);
        bait = new Moi(width,height);
        Score=0;
        GameOver = false;
    }
    ~GameFunction ()
    {
        delete snake,bait;
    }
    void setCursorPosition(int x, int y)
    {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
    }
    void CentreMess(string s)
    {
        for (int i=0;i<w;i++)
            cout<<"\xB2";
        cout<<endl;
        cout<<"\xB2";
        bool pri = true;
        while (s.length()<w-2)
        {
            if (pri) s= s+" ";
            else s= " "+s;
            pri = !pri;
        }
        cout<<s;
        cout<<"\xB2"<<endl;
        for (int i=0;i<w;i++)
            cout<<"\xB2";
        cout<<endl;
    }
    void InlineMess(string s)
    {
        cout<<"\xB2";
        while (s.length()<w-2)
        {
            s=s + " ";
        }
        cout<<s;
        cout<<"\xB2"<<endl;
    }
    void Draw()
    {
        //system("cls");
        string mess= "THE SNAKE GAME"
        ,mess2 = "W , S , A , D to move"
        ,mess4 ="Q to quit";
        CentreMess(mess);
        InlineMess(mess2);
        InlineMess(mess4);
        for (int i=0;i<w;i++)
            cout<<"\xB1";
        cout<<endl;
        //
        for (int j=1;j<h-1;j++)
        {
            for (int i=0;i<w;i++)
            {
                if (i == 0 || i == w-1) cout<<"\xB1";
                else cout<<" ";

            }
            cout<<endl;
        }
        for (int i=0;i<w;i++)
            cout<<"\xB1";
        cout<<endl;
        SetConsoleTextAttribute(color,4);
        setCursorPosition(bait->x,bait->y+4); cout<<"*";
    }
    void Input()
    {
        if (_kbhit())
        {
            switch(_getch())
            {
            case 'w':
                if (snake->Dir !=DOWN) snake->Dir = UP;
                break;
            case 's':
                if (snake->Dir !=UP) snake->Dir = DOWN;
                break;
            case 'a':
                if (snake->Dir !=RIGHT) snake->Dir = LEFT;
                break;
            case 'd':
                if (snake->Dir !=LEFT) snake->Dir = RIGHT;
                break;
            default:
                break;
            }
        }
    }
    void Logic()
    {
        setCursorPosition(xPrevSnake,yPrevSnake+4); cout<<" ";
        for (int i=0;i<snake->nTail;i++)
        {
            setCursorPosition(xPrevTail[i],yPrevTail[i]+4); cout<<" ";
        }
        snake->MakeTail();


        xPrevSnake = snake->x;
        yPrevSnake = snake->y;
        for (int i=0;i<snake->nTail;i++)
            {
                xPrevTail[i] = snake->xTail[i];
                yPrevTail[i] = snake->yTail[i];
            }
        snake->Move();
        SetConsoleTextAttribute(color,2);
        setCursorPosition(snake->x,snake->y+4); cout<<"0";
        for (int i=0;i<snake->nTail;i++)
        {
            setCursorPosition(snake->xTail[i],snake->yTail[i]+4); cout<<"o";
        }
        if (snake->x == bait->x && snake->y == bait->y)
        {
            Speed-=20;
            Score++;
            bait->x = (rand() % (w-2) ) +1;
            bait->y = (rand() % (h-2) ) +1;
            snake->nTail ++;
            cout<<'\a';
            SetConsoleTextAttribute(color,4);
            setCursorPosition(bait->x,bait->y+4); cout<<"*";

        }
        if (snake->x == 0 || snake->x == w-1||
            snake->y == 1|| snake->y == h)
        {
            GameOver = true;
        }
        for (int i=0;i<snake->nTail;i++)
        {
            if (snake->x == snake->xTail[i+1] && snake->y == snake->yTail[i+1])
                GameOver = true;
        }
    setCursorPosition(0,h+6);
    cout<<"Score :"<<Score<<endl;
    _score = Score;
    }
    void Run()
    {
        Draw();
        while (!GameOver)
        {
            Sleep(Speed);
            Input();
            Logic();
        }

    }
};


#endif // GAMEMANAGER_H_INCLUDED

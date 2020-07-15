#ifndef BAIT_H_INCLUDED
#define BAIT_H_INCLUDED
#include <iostream>
#include <conio.h>
using namespace std;

class Moi
{
public:
    int x,y;
    Moi (int width,int height)
    {
        x = (rand() % width-2 ) +1;
        y = (rand() % height-2 ) +4;
    }

};

#endif // BAIT_H_INCLUDED

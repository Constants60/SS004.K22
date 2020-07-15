#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "GameManager.h"
using namespace std;
int diem_cao = 0;
void gotoxy(int column, int line)

{

    COORD coord;

    coord.X = column;

    coord.Y = line;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int move() {

    char c = _getch();

    if ((int)c == -32) c = _getch();

    switch ((int)c) {

    case 80:  //xuong
        return 1;

    case 72:    //len
        return 2;

    case 77:    //phai
        return 3;

    case 75:     //trai
        return 4;

    case 27: //ESC thoat 
        return 8;

    case 13: //enter 
        return 5;

    default:
        return 0; //sai

    }

}

class Menu {

public:

    Menu();

    ~Menu() {}

    void printMenu();

    void deleteMenu();

    int numberOfItem() {
        return _numberOfItem;
    }

    string* getItem() {
        return item;
    }

private:

    string* item;

    int _numberOfItem;

};

Menu::Menu() {

    item = new string[100];

    _numberOfItem = 4;

    item[0] = "CHOI";

    item[1] = "DIEM CAO NHAT";

    item[2] = "HUONG DAN";

    item[3] = "THOAT";

}
void huong_dan();
void Menu::printMenu() {
    huong_dan();
    for (int i = 0; i < _numberOfItem; i++) {

        gotoxy(3, i);

        cout << item[i];

        Sleep(100);

    }

}

void Menu::deleteMenu() {

    for (int i = 0; i < _numberOfItem; i++) {

        Sleep(100);
        gotoxy(0, i);
        for (int j = 0; j < item[i].size() + 3; j++) {
            cout << " ";
        }
    }
}

void huong_dan()
{
    gotoxy(20, 0); cout << " dung cac phim mui ten di chuyen.";
    gotoxy(20, 1); cout << "Nhan Enter de nhap.Nhap ESC de thoat";
}


void menu()
{

    Menu menu;

    int x;

    int line = 0;

    bool thoat = false;
    
    

    gotoxy(0, line);
    cout << (char)254;
    menu.printMenu();
    while (!thoat) {     
        if (_kbhit()) {
            x = move();
            gotoxy(0, line);
            cout << " ";

            switch (x) {
            case 1:
            case 3:
            {
                line++;
                if (line >= menu.numberOfItem()) line = 0;
                break;
            }
            case 2:
            case 4:
            {
                line--;
                if (line < 0) line = menu.numberOfItem() - 1;
                break;
            }
            case 5:
            {
                if (line == 0) {
                    system("cls");
                    GameFunction a(60, 40);
                    a.Run();
                    system("cls");
                    menu.printMenu();
                }
                if (line == 1) {
                    system("cls");
                    if (_score > diem_cao) diem_cao = _score;
                    cout << "\n\t\tDIEM CAO NHAT CUA BAN LA : ";
                    cout << _score << endl;
                    system("pause");
                    system("cls");
                    menu.printMenu();
                }
                if (line == 2)
                {
                    system("cls");
                    cout << "su dung cac phim A S D W de di chuyen con ran\n";
                    cout << "an moi de tang diem so\n";
                    cout << "tranh dung vao tuong hoac than ran de khong bi thua";
                    system("pause");
                    system("cls");
                    menu.printMenu();
                }
                break;

            }

            case 8:

                thoat = true;

            }
            
            gotoxy(0, line);
            cout << (char)254;

        }

    }

    menu.deleteMenu();

}


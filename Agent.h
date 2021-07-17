#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include "Board.h"
/// this header file only contains the class agent

using namespace std;

class agent{
    char graphic;
    board variable; //ADT
public:
    agent();
    void Move(int pieces[16][2], int &x, int&y);
    int detectObj(int pieces[16][2], int& x, int& y);
    int detectObjRight(int pieces[16][2], int& x, int& y);
    int detectObjLeft(int pieces[16][2], int& x, int& y);
    int randCoord();
    void SetPieces(int pieces[16][2]);
    void UpdateGrid(int pieces[16][2], char grid[17][17], int& x, int& y, int& prev_x, int& prev_y);

    void setup(char grid[17][17], int enemy[16][2], int& x, int& y, int& prevX, int& prevY);
    void game(char grid[17][17], int enemy[16][2], int& x, int& y, int& prevX, int& prevY);
};

#endif // AGENT_H_INCLUDED

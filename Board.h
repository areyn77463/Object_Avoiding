#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
/// only contains the class board
#include <iostream>
#include <ctime>


using namespace std;

class board{
    char grid[17][17];
public:
    void SetGrid(char grid[17][17]);
    void GridInit(char grid[17][17]);
    void PrintGrid(char grid[17][17]);
};

#endif // BOARD_H_INCLUDED

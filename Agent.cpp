#include "Agent.h"
/// constructor to set agent graphic
agent::agent(){
    graphic='A';
}
///a function for a random number
int agent::randCoord()
{
    return rand()%14 + 1;
}
/// sets the enemy pieces coordinates
void agent::SetPieces(int pieces[16][2])
{
        for(int i=0; i<16; i++)
        {
            pieces[i][0] = randCoord();
            pieces[i][1] = i+1;
        }
}
/// updates the grid for the next print
void agent::UpdateGrid(int pieces[16][2], char grid[17][17], int& x, int& y, int& prev_x, int& prev_y){

    grid[prev_x][prev_y] = ' ';
    for(int i=0; i<16; i++){
            grid[pieces[i][1]][pieces[i][0]]='X'; // fix this
    }
    if(x != 0 && x!= 16 && y!=0 && y!=16)
        grid[x][y]=graphic;
}
/// a series of obstacle detection functions for ahead and beside agent
int agent::detectObj(int pieces[16][2], int& x, int& y){
    int z=0;
    for(int i=0; i<16; i++){
        int r = pieces[i][0];
        int c = pieces[i][1];
        if(x-1 == c && y == r)
            z=1;
    }
    return z;
}
int agent::detectObjRight(int pieces[16][2], int& x, int& y){
    int z=0;
    for(int i=0; i<16; i++){
        int r = pieces[i][0];
        int c = pieces[i][1];
        if(x == c && y+1 == r)
            z=1;
    }
    return z;
}
int agent::detectObjLeft(int pieces[16][2], int& x, int& y){
    int z=0;
    for(int i=0; i<16; i++){
        int r = pieces[i][0];
        int c = pieces[i][1];
        if(x-1 == c && y-1 == r)
            z=1;
    }
    return z;
}
/// moves the agent forward unless there is in obstacle in which case it will
///use detection functions to determine where to move
void agent::Move(int pieces[16][2], int& x, int& y){
    if(detectObj(pieces,x,y)==1){
        if(detectObjLeft(pieces,x,y)==1 && detectObjRight(pieces,x,y)==1){
            x++;
            y++;
        }
        else if(detectObjRight(pieces,x,y)==1)
            y--;
        else if(detectObjLeft(pieces,x,y)==1)
            y++;
        else
            y++;
    }
    else x--;
}
/// uses class board functions to setup the map
void agent::setup(char grid[17][17], int enemy[16][2], int& x, int& y, int& prevX, int& prevY){
    variable.GridInit(grid);
    variable.SetGrid(grid);
    SetPieces(enemy);
    UpdateGrid(enemy,grid,x,y,prevX,prevY);
}
///uses class board function to print map
/// this function is the game with movement and detection
void agent::game(char grid[17][17], int enemy[16][2], int& x, int& y, int& prevX, int& prevY){
        prevX=x;
        prevY=y;
        Move(enemy,x,y);
        UpdateGrid(enemy,grid,x,y,prevX,prevY);
        variable.PrintGrid(grid);
}

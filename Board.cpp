#include "Board.h"
/// this function initializes the grid
void board::GridInit(char grid[17][17])
{
    for(int i=0; i<17; i++)
    {
        for(int j=0; j<17; j++)
            grid[i][j]=' ';
    }
}


void board::SetGrid(char grid[17][17])
{
    for(int i=0; i<17; i++)
    {
        for(int j=0; j<17; j++)
        {
            if(i==0 || i==16)
                grid[i][j]='-';
            else
            {
                if(j==0 || j==16)
                    grid[i][j]='|';
                else
                    cout<<' ';
            }
        }
    }
}
/// this function prints the grid to the screen
void board::PrintGrid(char grid[17][17]){
    system("CLS");
     for(int i=0; i<17; i++)
    {
        for(int j=0; j<17; j++)
        {
            if(i==0 || i==16)
                grid[i][j]='-';
            else{
                if(j==0 || j==16)
                    grid[i][j]='|';
            }
        }
    }

    for(int i=0; i<17; i++)
    {
        for(int j=0; j<17; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
}



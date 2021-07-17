#include "Agent.h"
///this is the menu function which holds the menu and the game
void menu(char grid[17][17], int enemy[16][2], int& x, int& y, int& prevX, int& prevY,
           agent player);
int main()
{
    srand(time(NULL)); // for different random numbers
    agent player;

    char b[17][17];
    int enemy[16][2];
    int x=16;
    int y=rand()%15+1;
    int prevX=10;
    int prevY=10;

    menu(b,enemy,x,y,prevX,prevY,player);

}

void menu(char b[17][17], int enemy[16][2], int& x, int& y, int& prevX, int& prevY,
          agent player){
    int run=3;
    char trash;
///menu should only take 1 or 0
    while(run!=0){
reenter:
    cout << "Run          (1)\nExit         (0)\n"
    << "Insert Action:";
    cin >> run;
    if(run!=1 && run!=0)
        goto reenter;
    if(cin.fail()){
        cin.clear();
        cin >> trash;
        goto reenter;
    }
    player.setup(b,enemy,x,y,prevX,prevY); //a function in class agent used to setup map

    if(run==1){
        while(x>0){
            player.game(b,enemy,x,y,prevX,prevY); // a function in class agent that is the game
    }
    cout << x << ", " << y << endl; // output final coordinates
    ///re initializes coordinates for agent
    x=16;
    y=rand()%15+1;
    }


}


}

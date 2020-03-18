//Nico Mingkun Xia 
#include <iostream>
#include "functions.h"
using namespace std;

int main(){
    //create a map of different cells, to remind user the index of cell
    int map[28] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    //create a vector and initialize to EMPTY
    char board[27];
    for(int i=0; i<27; i++){
        board[i] = ' ';
    }
    greetAndInstruct();
    displayBoard(board);
    int iter = 0; 
    int cellNbre;
    while(iter<100){
        iter++;
        cout<<"Your turn! Input a cell number to occupy.\n";
        cin>>cellNbre;
        while(!checkIfLegal(cellNbre,board)){
            cin>>cellNbre;
        }
        displayLayout(map);
        //player makes move
        board[cellNbre-1] = 'x';
        displayBoard(board);
        if(checkWinner(board)){
            cout<<"YOU WIN! Can't believe it!!\n";
            exit(0);
        }
        cout<<"Computer's turn.\n";
        displayLayout(map);
        //computer makes move
        computerMove(board);
        displayBoard(board);
        if(checkWinner(board)){
            cout<<"COMPUTER WIN!I know I'm better than you HAHA!\n";
            exit(0);
        }
  
    }
    
    return 0;
}

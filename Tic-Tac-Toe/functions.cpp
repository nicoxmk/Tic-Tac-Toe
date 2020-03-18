//Nico Xia 260770119
#include <iostream>
using namespace std;
const char x = 'x';
const char o = 'o';
const char EMPTY = ' ';


void greetAndInstruct(){
	cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer\n";
	cout <<"The board is numbered from 1 to 27 as per the following:\n";
	cout << "\t1 | 2 | 3\t10 | 11 | 12\t19 | 20 | 21\n";
    cout << "\t---------\t-------------\t-------------\n";
    cout << "\t4 | 5 | 6\t13 | 14 | 15\t22 | 23 | 24\n";
    cout << "\t---------\t-------------\t------------------\n";
    cout << "\t7 | 8 | 9\t16 | 17 | 18\t25 | 26 | 27\n\n";
   
	cout << "Players starts first. Input the number of the cell you want to occupy.\n";
	cout << "Player: X ; Computer: O\n";
    char response;
    
    cout << "ARE YOU READYYY? (y/n)\n";
    cin >> response;
    if(response == 'n'){
        cout << "Game exit!\n";
        exit(0);
    }
    
    else{
        cout << "Game start!\n";
    }
}

void displayBoard(char board[]){
    //display Board and every move made will show up here
    cout << "\n\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2]
        << "\t"<<board[9]<<" | "<<board[10]<<" | "<<board[11]
        << "\t"<<board[18]<<" | "<<board[19]<<" | "<<board[20];
    cout << "\n\t" << "---------\t---------\t---------\n";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5]
        << "\t"<<board[12]<<" | "<<board[13]<<" | "<<board[14]
        << "\t"<<board[21]<<" | "<<board[22]<<" | "<<board[23];
    cout << "\n\t" << "---------\t---------\t---------\n";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8]
        << "\t"<<board[15]<<" | "<<board[16]<<" | "<<board[17]
        << "\t"<<board[24]<<" | "<<board[25]<<" | "<<board[26];
    cout << "\n\n";
    
}

void displayLayout(int board[]){
    //simplay display the layout to remind player of index of cells to choose
    cout << "\n\t"<<board[1]<<" | "<<board[2]<<" | "<<board[3]
        << "\t"<<board[10]<<" | "<<board[11]<<" | "<<board[12]
        << "\t"<<board[19]<<" | "<<board[20]<<" | "<<board[21];
    cout << "\n\t" << "---------\t-------------\t-------------\n";
    cout << "\n\t" << board[4] << " | " << board[5] << " | " << board[6]
        << "\t"<<board[13]<<" | "<<board[14]<<" | "<<board[15]
        << "\t"<<board[22]<<" | "<<board[23]<<" | "<<board[24];
    cout << "\n\t" << "---------\t-------------\t-------------\n";
    cout << "\n\t" << board[7] << " | " << board[8] << " | " << board[9]
        << "\t"<<board[16]<<" | "<<board[17]<<" | "<<board[18]
        << "\t"<<board[25]<<" | "<<board[26]<<" | "<<board[27];
    cout << "\n\n";
    
}

bool checkIfLegal(int cellNbre, char board[]){
    if(cellNbre>27||cellNbre<1){
        cout << "Cell number out of bound,input another one.\n";
        return false;
    }
    else if(board[cellNbre-1]==x || board[cellNbre-1]==o){
        cout<<"Cell has been taken,input another one.\n";
        return false;
    }else{
        return true;
    }
}

bool checkWinner(char board[]){
    //a 2D int array, to put all possible wining situations together
    //in total 49 combinations
    const int WINING[49][3] = {{0,1,2},{3,4,5},{6,7,8},{9,10,11},
    {12,13,14},{15,16,17},{18,19,20},{21,22,23},{24,25,26},{0,3,6},
    {1,4,7},{2,5,8},{9,12,15},{10,13,16},{11,14,17},{18,21,24},
    {19,22,25},{20,23,26},{0,4,8},{2,4,6},{9,13,17},{11,13,15},
    {18,22,26},{20,22,24},{0,10,20},{0,13,26},{0,12,24},{1,13,25},
    {2,13,24},{2,10,18},{2,14,26},{3,13,23},{5,13,21},{6,12,18},
    {6,16,26},{6,13,20},{7,13,19},{8,14,20},{8,13,18},{8,16,24},
    {0,9,18},{1,10,19},{2,11,20},{3,12,21},{4,13,22},{5,14,23},
    {6,15,24},{7,16,25},{8,17,26}};
    //check in board if these cells are all equal-signs
    for(int row = 0; row < 49; row++)
    {
        if ( (board[WINING[row][0]] != EMPTY) &&
             (board[WINING[row][0]] == board[WINING[row][1]]) &&
             (board[WINING[row][1]] == board[WINING[row][2]]) &&
             (board[WINING[row][0]] == board[WINING[row][2]]))
        {
            return true; 		
        }
    }
    return false;   
}

    
void computerMove(char board[]){
  
    //case#1: find the move that computer will win
    for(int cellNbre=1; cellNbre<=27; cellNbre++){
        if(board[cellNbre-1]==EMPTY && checkIfLegal(cellNbre,board)){
            //try move to see if computer will win
            board[cellNbre-1] = o;
            if(checkWinner(board)){
                cout<<"COMPUTER: See I put it here: "<<cellNbre<<endl;
                return;
            }
            else {
                //if no such situation, reset this cell
                board[cellNbre-1] = EMPTY;
                 //cout<<"heree\n";
            }
        }
    }
    
    
    //case#2:find the move that user will win and block it 
    for(int cellNbre=1; cellNbre<=27; cellNbre++){
        if((board[cellNbre-1]==EMPTY) && checkIfLegal(cellNbre,board)){
            //pretend player's move to see if player will win
                board[cellNbre-1] = x;
            if(checkWinner(board)){
                //change this cell to computer's move
                board[cellNbre-1] = o;
                cout<<"COMPUTER: Don't try to trick me HUMAN,I blocked you at "<<cellNbre<<endl;
                return;
            }
            else {
                //if no such situation, reset this cell
                board[cellNbre-1] = EMPTY;
                 //cout<<"here\n";
            }
    }
}
    // //case#3: put mark on center in priority of random pick
    // //This case aims to increase (a bit) of intelligence of computer
    // //since marking on center gives user less ideal cell to choose
    // for(int cellNbre=5; cellNbre<=14;cellNbre+9){
    //     if(board[cellNbre]==EMPTY && checkIfLegal(cellNbre,board)){
    //         //cout<<"Computer put at center: "<<cellNbre<<endl;
    //         board[cellNbre] = o;
    //         cout<<"hereee\n";
    //         return;
    //     }
    // }
    //case#4: if none of them above, random choose a cell
    srand(time(0));
    int r = rand()%27+1; 
    while(!checkIfLegal(r,board)){
        r = rand()%27+1;
    }
    board[r-1] = o;
        cout<<"COMPUTER: Let me randomly choose here: "<<r<<endl;
        return;

       
    
}











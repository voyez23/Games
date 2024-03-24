// Annica Steinberg

#include <iostream>
using namespace std;

void boardPrint(char board[3][3]){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isWinner(char board[3][3]){
    for (int i = 0; i < 3; i++){ 
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] == 'X' || board[i][0] == 'O')){ // rows
            return true;
        }
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == 'X' || board[0][i] == 'O')) { // columns
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[1][1] == 'X' || board[1][1] == 'O')){
        return true;
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[2][0] == 'X' || board[2][0] == 'O')){
        return true;
    }
    return false;
}
bool checkSpot(char board[3][3], int x, int y){
    if (board[x][y] != '_') {
        return false;
    } else {
        return true;
    }
}
bool stalemate(char  board[3][3]){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == '_') { //empty spot found, a move remains
                return false;
            }
        }
    }
    return true;
}

int main(){
    bool status = true;
    char random;
    int x, y;
    int player = 0; // %2==0 is p1, else p2
    char board[3][3] = {{'_','_','_'},{'_','_','_'}, {'_','_','_'}};
    string p1, p2 = "";
    cout << "Playing Tic Tac Toe" << endl;
    cout << "Please enter player 1's name: ";
    cin >> p1;
    cout << "Please enter player 2's name: ";
    cin >> p2;
    cout << p1 << " vs " << p2 << " ......\nBEGIN!" << endl;

    // First Move
    boardPrint(board);
    cout << p1 << ": enter move (0-2,0-2), with (0,0) being the top left corner." << endl;
    cin >> random >> x >> random >> y >> random;
    if ((x < 0 || x > 2) || (y < 0 || y > 2)){
        cout << "Invalid entry, please try again" << endl;
    } else {
        board[x][y] = 'X';
        player++;
    }

    while(status){
        boardPrint(board);
        if(player % 2 ==0){
            cout << p1 << ": " << endl;
        } else {
            cout << p2 << ": " << endl;
        }
        cin >> random >> x >> random >> y >> random;
        if ((x < 0 || x > 2) || (y < 0 || y > 2)){
            cout << "Invalid entry, please try again" << endl;
            continue;
        }
        if (!checkSpot(board, x, y)) {
            cout << "Someone already played here! Try again." << endl;
            continue;
        }

        if(player % 2 ==0){
            board[x][y] = 'X';
            player++;
        } else {
            board[x][y] = 'O';
            player++;
        }
        if (isWinner(board)) {
            boardPrint(board);
            string name;
            if(player % 2 ==0){
                name = p2;
            } else {
                name = p1;
            }
            cout << "WE HAVE A WINNER!!!!!\n CONGRATS " << name << "!!" << endl;
            status = false;
        }
        else if (stalemate(board)) {
            cout << "Stalemate reached, no winner. Please play again!" << endl;
            status = false;
        }
        
    }


}
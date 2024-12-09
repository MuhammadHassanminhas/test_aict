#include <iostream>
using namespace std;

const int SIZE = 3;

void Display(char board[SIZE][SIZE]){
	  cout << "  0 1 2"<<endl;
	  
	   for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << "|";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "  -----"<<endl;
    } 
}

bool checkWin(char board[SIZE][SIZE], char player) {
  
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { 
            return true;
        }
    }
 
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

int main() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

      
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue; 
        }

        board[row][col] = currentPlayer; 

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

      
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

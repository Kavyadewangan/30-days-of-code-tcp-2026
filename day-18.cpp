#include <iostream>
using namespace std;

char board[10][10];   
bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}
void printBoard(int n) {
    cout << "Solution"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void solveNQueens(int row, int n) {

    if (row == n) {
        printBoard(n);
        return;
    }
    for (int col = 0; col < n; col++) {

        if (isSafe(row, col, n)) {

            board[row][col] = 'Q';      
            solveNQueens(row + 1, n);   
            board[row][col] = '.';      
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    // Initialize board with '.'
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '.';

    solveNQueens(0, n);

    return 0;
}

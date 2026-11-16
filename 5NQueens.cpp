#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Check if placing a queen at (row, col) is safe from all placed queens
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                // Attack condition: same column or diagonal |j - col| == |i - row|
                if (j == col || abs(i - row) == abs(j - col))
                    return false;
            }
        }
    }
    return true;
}

// Backtracking function to place queens row by row
bool solveNQueens(vector<vector<int>> &board, int row, int N, int firstRow) {
    if (row == N)
        return true;

    // Skip the row where the first queen is already placed
    if (row == firstRow)
        return solveNQueens(board, row + 1, N, firstRow);

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place queen

            if (solveNQueens(board, row + 1, N, firstRow))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int N, r, c;
    cout << "Enter board size N (e.g., 8 for 8-Queens): ";
    cin >> N;

    cout << "Enter position (row and col, 0-indexed) for first Queen: ";
    cin >> r >> c;

    if (r < 0 || r >= N || c < 0 || c >= N) {
        cout << "Invalid position!\n";
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));
    board[r][c] = 1; // Place the first queen

    if (solveNQueens(board, 0, N, r)) {
        cout << "\nFinal " << N << "-Queens Matrix:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nNo solution exists with the first Queen at (" << r << ", " << c << ").\n";
    }

    return 0;
}
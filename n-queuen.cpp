# QUESTION NUMBER 7: write a program to solve n-queen's problem using backtraching.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to print the board
void printSolution(const vector<int>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                cout << "Q ";  // Place a queen
            else
                cout << ". ";  // Empty space
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if the column or diagonal is attacked
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(vector<int>& board, int row, int N) {
    if (row == N) {  // If all queens are placed, print the solution
        printSolution(board, N);
        return true;  // Return true to find one solution
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {  // Check if it's safe to place a queen
            board[row] = col;  // Place queen
            foundSolution = solveNQueens(board, row + 1, N) || foundSolution;
            // If placing queen doesn't lead to a solution, backtrack
            board[row] = -1;
        }
    }
    return foundSolution;
}

int main() {
    int N;
    cout << "Enter the value of N (size of the board): ";
    cin >> N;

    vector<int> board(N, -1);  // Initialize a vector to represent the board

    // Call the backtracking function to solve the N-Queens problem
    if (!solveNQueens(board, 0, N)) {
        cout << "No solution exists for N = " << N << endl;
    }

    return 0;
}

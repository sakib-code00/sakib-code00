#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    if (col == n) {
        // All queens are placed successfully
        // Print the solution or perform other actions
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col, n)) {
            // Place queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            res = solveNQueensUtil(board, col + 1, n) || res;

            // If placing queen in the current position doesn't lead to a solution,
            // then remove queen from the current position (backtrack)
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueensUtil(board, 0, n)) {
        cout << "Solution does not exist." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N for N-Queens: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}

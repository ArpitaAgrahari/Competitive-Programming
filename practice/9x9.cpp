#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& grid, int row, int col, int num) {
    // Check row, column, and 3x3 subgrid
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num || grid[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    if (row == 9) {
        return true; // Solved
    }

    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }

    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid, 0, 0)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
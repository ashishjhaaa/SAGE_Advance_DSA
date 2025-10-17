#include <bits/stdc++.h>
using namespace std;

int N;
int totalSolution = 0;

// print board
void printBoard(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
}

// check if the digit at grid[row][col] is safe or not
bool isSafe(int row, int col, int x, vector<vector<int>> board)
{
    // row check
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == x)
        {
            return false;
        }
    }

    // column check
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == x)
        {
            return false;
        }
    }

    // 3x3 sub-grid check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == x)
            {
                return false;
            }
        }
    }
    return true;
}

// Recursive function to find all sudoku solutions
void solveSudoku(int row, int col, vector<vector<int>> board)
{
    // If we reached end of the board (n-1, n-1)
    if (row == N - 1 and col == N)
    {
        totalSolution++;
        printBoard(board);
        return;
    }

    // Move to next row if we are at end of the column (N)
    if (col == N)
    {
        solveSudoku(row + 1, 0, board);
        return;
    }

    // If value is not 0, that means skip kar de (go to the next column)
    if (board[row][col] != 0)
    {
        solveSudoku(row, col + 1, board);
        return;
    }

    // If value is 0, that means put some value (1-9)
    for (int x = 1; x <= N; x++)
    {
        if (isSafe(row, col, x, board))
        {
            board[row][col] = x; // 1
            solveSudoku(row, col + 1, board);
            board[row][col] = 0; //////////// backtracking
        }
    }
}
int main()
{
    int n;
    cin >> n;

    N = n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << endl
         << endl;
    ;
    solveSudoku(0, 0, board);

    cout << "Total possible solutions = " << totalSolution << endl;

    if (totalSolution == 0)
    {
        cout << "No valid solution. Do some hardwork" << endl;
    }
}

// N Queen 
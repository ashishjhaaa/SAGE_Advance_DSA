#include <bits/stdc++.h>
using namespace std;
int totalPlaces = 0;
void printBoard(vector<vector<char>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "-------------------------------------" << endl;
}

bool isSafe(int row, int col, int n, vector<vector<char>> board)
{
    // check in col
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // check in left diagonal
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    // check in right diagonal
    for (int r = row, c = col; r >= 0 && c < n; r--, c++)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void NQueen(int row, int n, vector<vector<char>> &board)
{
    // base case
    if (row == n)
    {
        totalPlaces++;
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            NQueen(row + 1, n, board);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    NQueen(0, n, board);

    cout << "The total possible ways to arrange " << n << " queens is : " << totalPlaces << endl;
}
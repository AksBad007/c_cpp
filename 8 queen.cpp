#include <iostream>
using namespace std;

void printQueens(int);
void queen(int row, int n);

int board[20], count;

int main() {
  int n;

  cout << "-N Queens Problem using Backtracking-";
  cout << "\n\n Enter number of Queens: ";
  cin >> n;
  queen(1, n);
  return 0;
}

int place(int row, int column) {
  int i;

  for (i = 1; i <= row - 1; ++i) {
    if (board[i] == column) return 0;
    else if (abs(board[i] - column) == abs(i - row)) return 0;
  }
  return 1;
}

void queen(int row, int n) {
  int column;

  for (column = 1; column <= n; ++column) {
    if (place(row, column)) {
      board[row] = column;
      if (row == n) printQueens(n);
      else queen(row + 1, n);
    }
  }
}

void printQueens(int n) {
  int i, j;

  cout << "\n\nSolution:\n\n" << ++count;
  for (i = 1; i <= n; ++i) cout << "\t" << i;
  for (i = 1; i <= n; ++i) {
    cout << "\n\n" << i;

    for (j = 1; j <= n; ++j) {
      if (board[i] == j) cout << "\tQ";
      else cout << "\t-";
    }
  }
}
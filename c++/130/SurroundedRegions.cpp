//source: https://leetcode.com/problems/surrounded-regions/

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVector(vector<vector<char>>& board) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      cout << board[i][j] << " ,";
    }
    cout << endl;
  }
}

void mark(vector<vector<char>> & board, int x, int y, int row, int col)
{
  if (board[x][y] == 'O') {
    board[x][y] = 'Y';
    if (x < row-1) {
      mark(board, x+1, y, row, col);
    }
    if (x > 0) {
      mark(board, x-1, y, row, col);
    }
    if (y < col-1) {
      mark(board, x, y+1, row, col);
    }
    if (y > 0) {
      mark(board, x, y-1, row, col);
    }
  }

}

void solve(vector<vector<char>>& board) {
  for (int i = 0; i < board.size(); ++i) {
    mark(board, i, 0, board.size(), board[i].size());
    mark(board, i, board[i].size()-1, board.size(), board[i].size());
  }
  for (int j = 0; j < board[0].size() ; ++j) {
    mark(board, 0, j, board.size(), board[0].size());
    mark(board, board.size()-1, j, board.size(), board[0].size());
  }

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
    for (int i = 0; i < board.size() ; ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'Y') {
          board[i][j] = 'O';
        }
      }
    }
}

struct point{
  point(int x, int y)
      : x_(x),
        y_(y)
  {
  }
  int x_, y_;
};

void solve_non_recursive(vector<vector<char>>& board) {
  if (board.size() == 0) {
    return;
  }
  queue<point> q;
  for (int i = 0; i < board[0].size(); ++i) {
    if (board[0][i] == 'O') {
      board[0][i] = 'Y';
      q.push(point(0, i));
    }
    if (board[board.size()-1][i] == 'O') {
      board[board.size()-1][i] = 'Y';
      q.push(point(board.size()-1, i));
    }
  }
  for (int j = 0; j < board.size(); ++j) {
    if (board[j][0] == 'O') {
      board[j][0] = 'Y';
      q.push(point(j, 0));
    }
    if (board[j][board[0].size()-1] == 'O') {
      board[j][board[0].size()-1] = 'Y';
      q.push(point(j, board[0].size()-1));
    }
  }
  while (!q.empty()) {
    point p = q.front();
    q.pop();
    if (p.x_ > 0 && board[p.x_-1][p.y_] == 'O') {
      board[p.x_-1][p.y_] = 'Y';
      q.push(point(p.x_-1, p.y_));
    }
    if (p.x_ < board.size()-1 && board[p.x_+1][p.y_] == 'O') {
      board[p.x_+1][p.y_] = 'Y';
      q.push(point(p.x_+1, p.y_));
    }
    if (p.y_ > 0 && board[p.x_][p.y_-1] == 'O') {
      board[p.x_][p.y_-1] = 'Y';
      q.push(point(p.x_, p.y_-1));
    }
    if (p.y_ < board[0].size() && board[p.x_][p.y_+1] == 'O') {
      board[p.x_][p.y_+1] = 'Y';
      q.push(point(p.x_, p.y_+1));
    }
  }
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
      if (board[i][j] == 'Y') {
        board[i][j] = 'O';
      }
    }
  }
}

int main ()
{
  vector<vector<char>> board = {
      {'X' ,'X' ,'X' ,'X'},
      {'X' ,'O' ,'O' ,'X'},
      {'X' ,'X' ,'O' ,'X'},
      {'X' ,'O' ,'X' ,'X'},
  };
  printVector(board);
  solve_non_recursive(board);
  cout << "res = " << endl;
  printVector(board);
	return 0;
}

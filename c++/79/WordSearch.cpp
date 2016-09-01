//source: https://leetcode.com/problems/word-search/

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool existHelper(vector<vector<char> >& board, int index, int i, int j, vector<vector<int> >& mask, string word)
    {
      if (board[i][j] != word[index] || mask[i][j] == 1)
        return false;
      if (index == word.size()-1)
        return true;
      mask[i][j] = 1;
      if ((i > 0 && existHelper(board, index+1, i-1, j, mask, word)) ||
          (i < board.size()-1 && existHelper(board, index+1, i+1, j, mask, word)) ||
          (j > 0 && existHelper(board, index+1, i , j-1, mask, word)) ||
          (j < board[0].size()-1 && existHelper(board, index+1, i, j+1, mask, word)))
        {
          return true;
        }
      mask[i][j] = 0;
      return false;
    }
    static bool exist(vector<vector<char> >& board, string word) {
        if (board.size() == 0 || word.size() == 0)
          return false;
        int row = board.size();
        int col = board[0].size();

        vector<vector<int> > mask(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i)
        {
          for (int j = 0; j < col; ++j)
          {
            if (board[i][j] == word[0])
            {
                if (existHelper(board, 0, i, j, mask, word))
                {
                  return true;
                }
            }
          }
        }
        return false;
    }
};

vector< vector<char> > buildBoard(char b[][5], int r, int c) {
    vector< vector<char> > board;
    for (int i=0; i<r; i++){
        vector<char> v(b[i], b[i]+c);
        cout << b[i] << endl;
        board.push_back(v);
    }
    cout << "----------" << endl;    
    return board;
}

int main ()
{

  string s;
  char b[3][5] ={ "ABCE", "SFCS", "ADEE" };
  vector< vector<char> > board = buildBoard(b, 3, 4);

  s = "SEE";
  cout << s << ":" << Solution::exist(board, s) << endl; 
  
  s = "ABCCED";
  cout << s << ":" << Solution::exist(board, s) << endl; 
  
  s = "ABCB";
  cout << s << ":" << Solution::exist(board, s) << endl; 
	return 0;
}

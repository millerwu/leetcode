//source: https://leetcode.com/problems/n-queens/

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    static bool isValid(int x, int y, vector<int>& solution)
    {
        for (int i = 0; i < y; ++i)
        {
            if (solution[i] == x || abs (solution[i] - x) == abs(i - y))
            {
               return false;
            }
        }
        return true;
    }

    static void solveNQueensHelper(int n , int y, vector<int>& solution, vector<vector<string> >& res)
    {
        if (n == y)
        {
            vector <string> s;
            for (int i = 0; i < n; ++i)
            {
                string row;
                for (int j = 0; j < n; ++j)
                {
                    row = row + (solution[i] == j ? 'Q' : '.');
                }
                s.push_back(row);
            }
            res.push_back(s);
            return;
        }
        for (int x = 0; x < n; ++x)
        {
            if (isValid(x, y, solution))
            {
                solution[y] = x;
                solveNQueensHelper(n, y+1, solution, res);
            }
        }

    }

    static vector<vector<string> > solveNQueens(int n) 
    {
      vector< vector<string> > res;
      vector<int> solution(n);
      solveNQueensHelper(n, 0, solution, res);  
      return res;
    }
};

void printV(vector< vector<string> > s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j < s[i].size(); ++j)
        {
            cout << s[i][j] << endl;
        }
        cout << endl;
    }
}

int main ()
{
    vector< vector<string> > s;
    s = Solution::solveNQueens(4);
    printV(s); 
	  return 0;
}

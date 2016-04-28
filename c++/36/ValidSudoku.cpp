//source: https://leetcode.com/problems/valid-sudoku/

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
	static bool isValidSudoku(vector<vector<char>>& board) {
		bool res = false;
		const int cnt = 9;
		bool hori[cnt][cnt] = {false};
		bool vert[cnt][cnt] = {false};
		bool squa[cnt][cnt] = {false};
    	for (int i = 0; i < board.size(); ++i)
	    {
	    	for (int j = 0; j < board[i].size(); ++j)
	    	{
	    		if (board[i][j] == '.')
	    		{
	    			continue;
	    		}
	    		int idx = board[i][j] - '0' - 1;
	    		if (hori[j][idx] == true)
	    		{
	    			return false;
	    		}
	    		hori[j][idx] = true;

	    		if (vert[i][idx] == true)
	    		{
	    			return false;
	    		}
	    		vert[i][idx] = true;
	    		int c = i/3 + (j/3)*3;
	    		if (squa[c][idx] == true)
	    		{
	    			return false;
	    		}
	    		squa[c][idx] = true;

	    	}
	    }
	    return true;    
    }
    
};

int main ()
{
	return 0;
}

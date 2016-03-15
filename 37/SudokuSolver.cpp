//source: https://leetcode.com/problems/sudoku-solver/

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

#include <iostream>



class Solution {
public:
	static const int sudokuSize = 9;
	bool row_mask[sudokuSize][sudokuSize];
	bool col_mask[sudokuSize][sudokuSize];
	bool area_mask[sudokuSize][sudokuSize];

	void initSudokuMask(vector<vector<char>>& broad) {
		memset(row_mask, false, sizeof(row_mask));
		memset(col_mask, false, sizeof(col_mask));
		memset(area_mask, false, sizeof(area_mask));

		for (int i = 0; i < sudokuSize; ++i)
		{
			for (int j = 0; j < sudokuSize; ++j)
			{
				if (broad[i][j] != '.')
				{
					int area = (i/3)*3 + j/3;
					int index = broad[i][j] - '1';
					row_mask[i][index] = col_mask[j][index] = area_mask[area][index] = true;
				}
			}
		}

	}
	bool recursiveSudoku(vector<vector<char>>& broad, int row, int col){
		if (row >= sudokuSize)
		{
			return true;
		}

		if (col >= sudokuSize)
		{
			return recursiveSudoku(broad, row+1, 0);
		}

		if (broad[row][col] != '.')
		{
			return recursiveSudoku(broad, row, col+1);
		}

        int area;
		for (int i = 0; i < sudokuSize; i++)
		{
			area = (row/3)*3 + col/3;
			if (row_mask[row][i] || col_mask[col][i] || area_mask[area][i])
			{
				continue;
			} else {
				broad[row][col] = i + '1';
				row_mask[row][i] = col_mask[col][i] = area_mask[area][i] = true;

				if (!recursiveSudoku(broad, row, col+1))
				{
					broad[row][col] = '.';
					row_mask[row][i] = col_mask[col][i] = area_mask[area][i] = false;
				} else {
					return true;
				}
			}
		}
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		initSudokuMask(board);
		recursiveSudoku(board, 0, 0);
    }


    
};

int main ()
{
	return 0;
}

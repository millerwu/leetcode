//source: https://leetcode.com/problems/spiral-matrix/

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]
*/

#include <iostream>
#include <vector>

class Solution {
public:
	static vector<int> spiralOrder(vector<vector<int> >& matrix) {
       	vector<int> res;
		if (matrix.size() == 0)
		{
			return res;
		}
		int max_x = matrix[0].size();
		int max_y = matrix.size();
		int total_size = max_x*max_y;
		int current_x = 0, current_y = 0;
		
		int mid_x = (current_x+max_x)/2;
		int mid_y = (current_y+max_y)/2;
		int direction = 0;
		
		while(1)
		{
			if (direction == 0) 
			{
				for (int i = current_x; i < max_x; i++)
				{
					cout << " " << matrix[current_y][i] << endl;
					res.push_back(matrix[current_y][i]);
				}
				current_y++;
			} else if (direction == 1)
			{
				for (int i = current_y; i < max_y; i++)
				{
					res.push_back(matrix[i][max_x-1]);
				}
				max_x--;
			} else if (direction == 2)
			{
				for (int i = max_x-1; i > current_x-1; i--)
				{
					res.push_back(matrix[max_y-1][i]);
				}
				max_y--;
			} else if (direction == 3)
			{
				for (int i = max_y-1; i > current_y-1; i--)
				{
					res.push_back(matrix[i][current_x]);
				}
				current_x++;
			}
			direction = ++direction%4;
			if (res.size() == total_size)
				break;
		}
		
		return res;
		
    }
    
};

void printVector(vector< vector<int> > test)
{
	for (int i = 0; i < test.size(); ++i)
	{
		for (int j = 0; j < test[i].size(); ++j)
		{
			cout << " " << test[i][j];
		}
		cout << endl;
	}
}


int main ()
{
	vector<int> test;
	vector< vector<int> > matrix;
	int number = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			test.push_back(number++);
		}
		matrix.push_back(test);
		test.clear();
	}
	printVector(matrix);
	
	vector<int> res = Solution::spiralOrder(matrix);
	for (int j = 0; j < res.size(); ++j)
	{
		cout << " " << res[j];
	}	
	return 0;
}

//source: https://leetcode.com/problems/spiral-matrix-ii/

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > matrix;
        if (n == 0)
        {
            return matrix;
        }
        vector<int> row(n);
        
        for (int i = 0; i < n; i++)
        {
            matrix.push_back(row);
        }
        int direction = 0;
        int index = 1;
        int start_x = 0, start_y = 0;
        int end_x = n-1, end_y = n-1;
        while (index <= n*n)
        {
            //cout << "direction = " << direction << endl;
            // cout << "start = " << start_x << " start_y = " << start_y << " end_x = " <<end_x << " end_y = " << end_y << endl;
            if (direction == 0)
            {
                for(int i = start_x; i <= end_x; i++)
                {
                    matrix[start_y][i] = index++;
                }
                start_y++;
            } else if (direction == 1)
            {
                for (int i = start_y; i <= end_y; i++)
                {
                    matrix[i][end_x] = index++;
                }
                end_x--;
            } else if (direction == 2)
            {
                for (int i = end_x; i >= start_x; i--)
                {
                    matrix[end_y][i] = index++;
                }
                end_y--;
            } else if (direction == 3)
            {
                for (int i = end_y; i >= start_y; i--)
                {
                    matrix[i][start_x] = index++;
                }
                start_x++;
            }
            direction = (direction+1)%4;
        }
        return matrix;
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
    vector< vector<int> > test = Solution::generateMatrix(3);
    printVector(test);
	return 0;
}

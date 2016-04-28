//source: https://leetcode.com/problems/rotate-image/

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static void rotate(vector< vector<int> >& matrix) {
		vector< vector<int> > f_matrix = matrix;
        for (int i = 0; i < matrix.size(); ++i)
        {
        	for (int j = 0; j < matrix[i].size(); ++j)
        	{
        		matrix[j][matrix.size()-1-i] = f_matrix[i][j];
        	}
        }
        return;
    }
};

void printMatrix(vector< vector<int> >& matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j <matrix[i].size() ; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main ()
{
	vector<int> test;
	for (int i = 0; i < 5; ++i)
	{
		test.push_back(i);
	}
	vector< vector<int> > matrix;
	for (int i = 0; i < 5; ++i)
	{
		matrix.push_back(test);
	}

	cout << "before rotate" << endl;
	printMatrix(matrix);

	Solution::rotate(matrix);
	cout << "after rotate" << endl;
	printMatrix(matrix);


	return 0;
}

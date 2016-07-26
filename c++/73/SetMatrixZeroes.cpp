//source: https://leetcode.com/problems/set-matrix-zeroes/

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void setZeroes(vector<vector<int> >& matrix) {
		if (matrix.size() == 0)
			return;
		vector<int> row;
		vector<int> col;

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row.push_back(i);
					col.push_back(j);
				}
			}
		}
        for (int i = 0; i < row.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				matrix[row[i]][j] = 0;
			}
		}
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < col.size(); j++)
			{
				matrix[i][col[j]] = 0;
			}
		}
		return;
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
	vector< vector<int> > test;
	vector<int> t;
	int temp = 0;
	for (int i = 0; i < 10; i ++)
	{
		for (int j = 0; j < 10; j++)
		{
			t.push_back(temp++);
		}
		test.push_back(t);
		t.clear();
	}
	printVector(test);

	Solution::setZeroes(test);

	printVector(test);

	return 0;
}

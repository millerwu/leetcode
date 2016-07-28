//source: https://leetcode.com/problems/search-a-2d-matrix/

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static int vBinarySearch(vector<vector<int> >& matrix, int target)
	{
		int l = 0;
		int row = matrix.size()-1;
		while (l<=row)
		{
			cout << "l = " << l <<  "row = " << row << endl;
			int mid = l + (row-l)/2;
			if (matrix[mid][0] == target)
				return mid;
			else if (matrix[mid][0] > target)
				row = mid-1;
			else 
				l = mid+1;
		}
		return l-1;
	}
	static bool binarySearch(vector<int>& matrix, int target)
	{
		int l = 0;
		int row = matrix.size()-1;
		while (l<=row)
		{
			int mid = l + (row-l)/2;
			if (matrix[mid] == target)
				return true;
			else if (matrix[mid] > target)
				row = mid-1;
			else 
				l = mid+1;
		}
		return false;
	}
    static bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = vBinarySearch(matrix, target);
		cout << row << endl;
		if (row < 0)
		{
		    return false;
		}
		return binarySearch(matrix[row], target);
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
	vector<vector<int> > vv;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			v.push_back(index * 2+1);
			index++;
		}
		vv.push_back(v);
		v.clear();
	}

	printVector(vv);
	bool isfind = Solution::searchMatrix(vv, 3);
	cout<< isfind << endl; 


	return 0;
}

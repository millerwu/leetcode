//source: https://leetcode.com/problems/minimum-path-sum/

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

*/

#include <iostream>
#include <vector>
#include <climits>
#include <string.h>

using namespace std;

void printMatrix(int* matrix, int m, int n);

class Solution {
public:
    static int minPathSum(vector<vector<int> >& grid) {
       if (grid.size()==0)
	   {
		   return 0;
	   } 
		int m = grid.size();
		int n = grid[0].size();
		int* maxrix = new int[m*n];
		memset(maxrix, 0, sizeof(int)*m*n);
		printMatrix(maxrix, m, n);
		maxrix[0] = grid[0][0]; 
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int top = i==0 ? INT_MAX : maxrix[n*(i-1)+j];
				int left = j==0 ? INT_MAX : maxrix[n*i+j-1];

				if (top==INT_MAX && left==INT_MAX)
					continue;
				maxrix[n*i+j] = grid[i][j] + (top>left ? left : top); 
			}
		}
		printMatrix(maxrix, m, n);

		int res = maxrix[m*n-1];
		delete[] maxrix;
		return res;
    }
};

void printMatrix(int* matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout << matrix[i*n+j] << " ";
        }
        cout << endl;
    }
}

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
	// int a[6][2] = {{7,2},{6,6},{8,6},{8,7},{5,0},{6,0}};
	int a[2][3] = {{1,2,5}, {3,2,1}};
	vector< vector<int> > grid;
    for(int i=0; i<2; i++){
        vector<int> v;
        for(int j=0; j<3; j++){
            v.push_back(a[i][j]);
        }
        grid.push_back(v);
    }

	printVector(grid);
	cout << "res = " << Solution::minPathSum(grid) << endl;
	return 0;
}

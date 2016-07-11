//source:https://leetcode.com/problems/unique-paths/

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.


*/

#include <iostream>
#include <stdlib.h>

using namespace std;

void printMatrix(int* matrix, int m, int n);

class Solution {
public:
    static int uniquePaths(int m, int n) {
        int* matrix = new int[m*n];
        printMatrix(matrix, m , n);
        
        for(int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    matrix[i*n+j] = 1;
                } else {
                    matrix[i*n+j] = matrix[i*n+j-1] + matrix[(i-1)*n+j]; 
                }
            }
        }
        printMatrix(matrix, m, n);
        int res = matrix[m*n-1];
        delete[] matrix;
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

int main (int argc, char** argv)
{
    int m = 0;
    int n = 0;
    if (argc == 3)
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);       
    } else {
        cout << "please input 2 param" << endl;
    }

    int res = Solution::uniquePaths(m, n);
    
    cout << "res = " << res << endl;
	return 0;
}

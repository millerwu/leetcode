//source: https://leetcode.com/problems/unique-paths-ii/

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.


*/

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(int* matrix, int m, int n);
void printMatrix(vector<vector<int> >& obstacleGrid);

class Solution {
public:
    static int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        int* matrix = new int[m*n];
      
        printMatrix(matrix, m, n);

        for (int i = 0; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
            if (i==0 && j==0 )
            {
              matrix[0] = obstacleGrid[0][0]==0 ? 1 : 0;
              continue;
            }
            if (i==0)
            {
              matrix[n*i+j] = (matrix[n*i+j-1] > 0)&&(obstacleGrid[i][j] == 0) ? 1 : 0;
              continue;
            }
            if (j==0)
            {
              matrix[n*i+j] = (matrix[n*(i-1)+j] > 0)&&(obstacleGrid[i][j] == 0) ? 1 : 0;
              continue;
            }
            int left = obstacleGrid[i][j-1] == 0 ? matrix[n*i+j-1] : 0;
            int top = obstacleGrid[i-1][j]==0 ? matrix[n*(i-1)+j] : 0;
            matrix[n*i+j] = (obstacleGrid[i][j] == 0) ? left + top : 0;
          }
        }
        int res = matrix[m*n-1];
        printMatrix(matrix, m, n);
        delete[] matrix;
        return res;        
    }
};

void printMatrix(vector<vector<int> >& obstacleGrid)
{
    for (int i = 0; i< obstacleGrid.size(); i++)
    {
      for (int j = 0; j < obstacleGrid[0].size(); j++)
      {
          cout << obstacleGrid[i][j] << " ";
      }
      cout << endl;
    }
}

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
    cout << endl;
}

int main ()
{
  int a[4][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  vector<vector<int> > grid;
  for (int i = 0; i < 4; i++)
  {
    vector<int> temp;
    for (int j = 0; j < 4; j++)
    {
      temp.push_back(a[i][j]);
    }
    grid.push_back(temp);
  }
  printMatrix(grid);
  
  cout << endl;

  cout << "res = " << Solution::uniquePathsWithObstacles(grid) << endl;
	return 0;
}

//source: https://leetcode.com/problems/pascals-triangle/

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > res;
	if (numRows <= 0)
	{
		return res;
	}
	vector<int> row(1, 1);
	res.push_back(row);
	
	for (int i = 2; i <= numRows ; ++i)
  {
  	int pre = 1;
  	for (int j = 1; j < i-1; ++j)
  	{
  		int temp = row[j];
  		row[j] += pre;
  		pre = temp;
  	}
  	row.push_back(1);
  	res.push_back(row);
  }    
  return res;
}

void printVector(vector<vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size() ; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout<< endl;
	}
}

int main (int argc, char** argv)
{
	int a = atoi(argv[1]);
	vector<vector<int> > res = generate(a);
	printVector(res);
	return 0;
}

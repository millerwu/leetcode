//source: https://leetcode.com/problems/pascals-triangle-ii/

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res;
    if (rowIndex < 0)
    {
    	return res;
    }
    res.push_back(1);
    for (int i = 2; i <= rowIndex+1 ; ++i)
    {
    	int pre = 1;
    	for (int j = 1; j < i-1 ; ++j)
    	{
    		int temp = res[j];
    		res[j] += pre;
    		pre = temp;
    	}
    	res.push_back(1);
    }
    return res;
}

void printVector(vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		/* code */
		cout << v[i] << " ";
	}
	cout << endl;
}

int main (int argc, char** argv)
{
	int a = atoi(argv[1]);
	vector<int> res = getRow(a);
	printVector(res);
	return 0;
}

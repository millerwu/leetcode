//source: https://leetcode.com/problems/gray-code/

/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> grayCode(int n) {
    	std::vector<int> res;
    	if (n < 0)
    	{
    		return res;
    	}
    	res.push_back(0);
    	for (int i = 0; i < n; ++i)
    	{
    		int heightBit = 1 << i;
    		int length = res.size();
    		for (int j = length-1; j >= 0 ; --j)
    		{
    			res.push_back(res[j]+heightBit);
    		}
    	}
        return res;
    }
};

void printVector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main ()
{
	int i;
	cin >> i; 
	std::vector<int> res = Solution::grayCode(i);
	cout << i << "\' grayCode is " << endl;
	printVector(res);
	return 0;
}

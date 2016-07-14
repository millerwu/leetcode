//source: https://leetcode.com/problems/edit-distance/

/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	static int min(int a, int b, int c)
	{
		return std::min(a, std::min(b, c));
	}

	static int minDistance(string word1, string word2) {

		int n1 = word1.size();
		int n2 = word2.size();

		if (n1==0) return n2;
		if (n2==0) return n1;

		vector<vector<int> > matrix(n1+1, vector<int>(n2+1));

		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i][0] = i;
		}
        for (int i = 0; i < matrix[0].size(); i++)
		{
			matrix[0][i] = i;
		}

		for (int i = 1; i<matrix.size(); i++)
		{
			for (int j = 1; j<matrix[0].size(); j++)
			{
				if (word1[i-1] == word2[j-1])
				{
					matrix[i][j] = matrix[i-1][j-1];
				} else {
					matrix[i][j] = min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1])+1;
				}
			}
		}
		int res = matrix[n1][n2];
		return res;
    }
};

int main ()
{
	string s1 = "a";
	string s2 = "b";

	cout << "res = " << Solution::minDistance(s1, s2) << endl;
	return 0;
}

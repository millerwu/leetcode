//source: 最长公共子序列问题，来自算法导论

/*

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxLengthString(string s1, string s2)
	{
		int m = s1.size();
		int n = s2.size();
		if (m == 0 || n == 0)
			return 0;
		vector<vector<int> > matrix(m+1, vector<int>(n+1));
		for (int i = 1; i< matrix.size(); i++)
		{
			for (int j = 1; j < matrix[0].size(); j++)
			{
				if (s1[i-1] == s2[j-1])
				{
					matrix[i][j] = matrix[i-1][j-1]+1;
				} else {
					matrix[i][j] = std::max(matrix[i-1][j], matrix[i][j-1]);
				}
			}
		}
		return matrix[m][n];
	}
};

int main ()
{
	string s1 = "abcdsssse";
	string s2 = "acde";
	cout << "res = " << Solution::maxLengthString(s1, s2) << endl;
	return 0;
}

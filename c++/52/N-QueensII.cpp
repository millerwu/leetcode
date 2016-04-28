//source:https://leetcode.com/problems/n-queens-ii/ 

/*

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/

#include <iostream>
#include <vector>

class Solution {
public:
	static bool isValid(int x, int y, vector<int>& solution)
	{
		for (int i = 0; i < y; i++)
		{
			if (solution[i] == x || abs(solution[i] - x) == abs(y - i))
			{
				return false;
			}
		}
		return true;
	}

	static void nQueensHelper(int n, int y, vector<int>& solution, int& res)
	{
		if (n == y)
		{
			res++;
		}
		
		for (int i = 0; i < n; i++)
		{
			if (isValid(i, y, solution))
			{
				solution[y] = i;
				nQueensHelper(n, y+1, solution, res);
			}
		}	
	}
	static int totalNQueens(int n) {
        int res = 0;
		vector<int> solution(n);
		nQueensHelper(n, 0, solution, res);
		return res;
    }
    
};

int main ()
{
	int res = Solution::totalNQueens(8);
	cout << "res = " << res << endl;
	return 0;
}

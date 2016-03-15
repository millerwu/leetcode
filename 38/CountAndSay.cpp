//source: https://leetcode.com/problems/count-and-say/

/*

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

*/

#include <iostream>
#include <string>

class Solution {
public:

	static string CAS_String(string input) {
		string res = "";
		int count = 1;
		char pre_num = input[0];
		for (int i = 1; i < input.size(); ++i)
		{
			if (pre_num == input[i])
			{
				count++;
			} else {
				res.append(1, (char)(count+'0'));
				res.append(1, pre_num);
				count = 1;
				pre_num = input[i];
			}
		}
		if (count != 0)
		{
			res.append(1, (char)(count+'0'));
			res.append(1, pre_num);
		}
		return res;
	}

	static string countAndSay(int n) {
		string res = "1";
        for (int i = 1; i < n; ++i)
        {
        	res = CAS_String(res);
        }
        return res;
    }
    
};

int main ()
{
	string test = Solution::countAndSay(6);
	cout << " res = " << test ;
	return 0;
}

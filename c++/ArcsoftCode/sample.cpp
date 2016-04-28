//source: http://acm.uestc.edu.cn/#/problem/show/1260

/*

*/

#include <iostream>
#include <string>

static int indexs[] = {6, 7, 3, 5, 4, 2};
static int nums[] = {9, 8, 7, 5, 4, 1};

class Solution {
public:
	
	static bool matchStickNumHelper(int total, int bit, int start, string& res) {
		//cout << "res = " << res << endl;
		if (total < 0 || bit < 0)
		{
			return false;
		}
		if (bit == 0 && total == 0) {
			return true;
		}
		
		for (int i = 0; i < 6; ++i)
		{
			//cout << "i = " << i << endl;
			if (total - indexs[i] < 0)
			{
				continue;
			}
			res += '0' + nums[i];
			if (matchStickNumHelper(total - indexs[i], bit - 1, i, res))
			{
				return true;
			} else{
				res.erase(res.end()-1);
				continue;
			}
		}
		return false;
	}


	static string matchStickNum(int total, int bit){

		string res = "";

		if ((total > 7*bit) || (total < 2* bit))
		{
			return "-1";
		}

		if (matchStickNumHelper(total, bit, 0, res))
		{
			return res;
		} else {
			return "-1";
		}
	}
    
};

int main ()
{
	int m, n;
	scanf("%d%d", &m, &n);
	string res = Solution::matchStickNum(m, n);
	cout << " res = " << res << endl;
	return 0;
}

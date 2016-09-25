//source: https://leetcode.com/problems/restore-ip-addresses/

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	static bool enableIpValue(string s)
	{
		if (s.size() > 1 && s[0] == '0')
		{
			return false;
		}
		int vaule_ = atoi(s.c_str());
		return vaule_>=0 && vaule_ <= 255;
	}
	static void restoreHelper(string& s, int strindex, int ipindex, vector<string>& output, vector<string>& res)
	{
		if (ipindex == 4)
		{
			if (strindex < s.size())
			{
				return;
			}
			string ipaddr = "";
			for (int i = 0; i < output.size(); ++i)
			{
				ipaddr += output[i];
				if (i < output.size()-1)
				{
					ipaddr += ".";
				}
			}
			res.push_back(ipaddr);
			return;
		}
		for (int i = 1; i < 4 && i + strindex <= s.size(); ++i)
		{
			string str_ = s.substr(strindex, i);
			if (!enableIpValue(str_))
			{
				continue;
			}
			output.push_back(str_);
			restoreHelper(s, strindex+i, ipindex+1, output, res);
			output.pop_back();
		}
		return;
	}
  static vector<string> restoreIpAddresses(string s) {
  	std::vector<string> res_;
  	if (s.size() < 4)
  	{
  		return res_;
  	}
  	std::vector<string> output_;
  	restoreHelper(s, 0, 0, output_, res_);
  	return res_;
      
  }
};

void printVectorString(std::vector<string> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
}

int main ()
{
	string ipstring = "010010";
	cout << "input = " << ipstring << endl;
	std::vector<string> vip = Solution::restoreIpAddresses(ipstring);
	cout << "output: " << endl;
	printVectorString(vip);
	return 0;
}

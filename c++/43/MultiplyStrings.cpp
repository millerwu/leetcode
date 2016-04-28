//source: https://leetcode.com/problems/multiply-strings/	
//data: 2016/03/11
//author WuMiaoLiang
/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	static string intostr(int num) {
        string res = "";
        if (num == 0)
        {
            return "0";
        }
        int tmp = 0;
        while (num > 0) {
            tmp = num%10;
            res.append(1, (char)(tmp+'0'));
            num = num/10;
        }
        //reverse(res.begin(), res.end());
		return res;
	}
	static string plus(string num1, string num2){
        string res = "";
        //reverse(num1.begin(), num1.end());
        //reverse(num2.begin(), num2.end());
        int maxsize = max(num1.size(), num2.size());
        int carry = 0;
        int num = 0;
        for (int i = 0; i < maxsize; ++i)
        {
            if (i >= num1.size())
            {
                num = (carry + num2[i] - '0')%10;
                carry = (carry + (num2[i] - '0'))/10;  
            } else if (i >= num2.size())
            {
                num = (carry + num1[i] - '0')%10;
                carry = (carry + (num1[i]-'0'))/10;
            } else {
                num = (carry + num1[i] - '0' + num2[i] - '0')%10;
                carry = (carry + (num1[i]-'0') + (num2[i] - '0'))/10;
            } 
            res.append(1, (char)(num+'0'));
        }
        if (carry > 0)
        {
            res.append(1, (char)(carry+'0'));
        }
        //reverse(res.begin(), res.end());
        return res;
	}
    static string multiply(string num1, string num2) {
    	string res = "";
    	
    	reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());

        int tmp_num1 = 0;
        int tmp_num2 = 0;
        string tmp_res = "";
        string tmp_res1 = "";
    	for (int i = 0; i <num1.size() ; ++i)
    	{
    		for (int j = 0; j < num2.size(); ++j)
    		{
                tmp_num1 = num1[i] - '0';
                tmp_num2 = num2[j] - '0';
                tmp_res = intostr(tmp_num1*tmp_num2);
                tmp_res.insert(tmp_res.begin(), j, '0');
                cout << " res = " << tmp_res << " res1 = " << tmp_res1 << endl;
                tmp_res1 = plus(tmp_res1, tmp_res);

                cout<< " numi = " << num1[i] << " numj = " << num2[j] << " res = " << tmp_res1 << endl;
    		}
            tmp_res1.insert(tmp_res1.begin(), i, '0');

            cout << " tmp_res1 = " << tmp_res1 << endl;
            res = plus(res, tmp_res1);
            tmp_res1 = "";
            cout << " res = " << res << endl;  
    	}
        cout << " res = " << res << endl;
        reverse(res.begin(), res.end());

        while (res.size() > 0) {
            if (res[0] == '0')
            {
                res.erase(res.begin());
                continue;
            }
            break;
        }


        return res.size()>0 ? res : "0";
        
    }
};

int main ()
{

    string string_num1 = "103";
    string string_num2 = "98";
    string string_sum = Solution::plus(string_num1, string_num2);
    string string_multi = Solution::multiply(string_num1, string_num2);
    cout << " string_num1 = " << string_num1 << endl;
    cout << " string_num2 = " << string_num2 << endl;
    cout << " string_sum = " << string_sum << endl;
    cout << " string_multi = " << string_multi << endl;
	return 0;
}

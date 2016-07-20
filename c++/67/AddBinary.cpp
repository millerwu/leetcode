//source:https://leetcode.com/problems/add-binary/

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".


*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static std::string addBinary(std::string a, std::string b) {
        if (a.size() == 0)
        {
            return b;
        }
        if (b.size() == 0)
        {
            return a;
        }
        int m = a.size();
        int n = b.size();
        std::string res = "";
        int carry = 0;
        for (int i = 1; i <= std::max(m, n); i++)
        {
            int ta = m<i ? 0 : a[m-i]-'0';
            int tb = n<i ? 0 : b[n-i]-'0';
            int t = (ta+tb+carry)%2;
            carry = (ta+tb+carry)/2;
            res.insert(res.begin(), t+'0');
        }
        if (carry)
        {
            res.insert(res.begin(), carry+'0');
        }
        return res;   
    }
};

#define TESTADD(a, b) cout<<a << " + " << b << " = " << Solution::addBinary(a, b) << endl;

int main ()
{
    TESTADD("1", "111");

	return 0;
}

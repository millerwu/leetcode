//source: https://leetcode.com/problems/decode-ways/

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static int numDecodings(string s) {
        if (s.size() == 0 || s[0] - '0' == 0)
        {
            return 0;
        }
        int size = s.size();
        vector<int> m(size+1, 0);
        m[0] = 1;
        for (int i = 1; i < size+1; i++)
        {
            if (i == 1)
            {
                m[i] = 1;
            }else if (s[i-1]-'0' == 0) //for '0' case
            {
                if (s[i-2] - '0' > 2 || s[i-2] - '0' == 0)
                    return 0;
                m[i] = m[i-2];
            } // for the char > 'z' case
            else if ((( (s[i-1]-'0')<7 && (s[i-1]-'0')>0 && (s[i-2]-'0')==2)) || (s[i-2]-'0')==1)
            {
                m[i] = m[i-1] + m[i-2];
            } else {
                m[i] = m[i-1];
            }
        }
        return m[size];
    }
};

#define TEST(X) cout<<X<<"\'s number is " << Solution::numDecodings(X) <<endl;
int main ()
{
    string s2 = "17";
    string s1 = "10";
    TEST(s1);
    TEST(s2);
	return 0;
}

//source: https://leetcode.com/problems/plus-one/

/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0)
        {
            return digits;
        }
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; i--)
        {
            int temp = digits[i]+carry;
            carry = temp/10;
            digits[i] = temp%10;
        }
        if (carry)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

void printVector(vector<int> test)
{
	for (int i = 0; i < test.size(); ++i)
	{
		cout << " " << test[i];
	}
    cout << endl;
}

int main ()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(9);
    v.push_back(9);

    vector<int> res = Solution::plusOne(v);

    printVector(res);
	return 0;
}

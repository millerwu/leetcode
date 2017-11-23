//source: https://leetcode.com/problems/string-to-integer-atoi/

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

#include <iostream>
#include <vector>

using namespace std;

//vaild int : "123"  "+111"  "-100"
//vaild "   010" "  +100 "
// why "  -0012a42" = -12?

int myAtoi(string str) {
  int sign = 0;
  int res = 0;
  bool start = false;
  bool end = false;
  for (int i = 0; i < str.size(); ++i) {
    // get " " before the string
    if (!start) {
      if (str[i] == ' ') {
        continue;
      } else if (isdigit(str[i]) || str[i] == '+' || str[i] == '-') {
        start =  true;
      } else {
        return 0;
      }
    }
    // get the sign before string
    if ( sign == 0 ) {
      if (str[i] == '+') {
        sign = 1;
        continue;
      } else if (str[i] == '-') {
        sign = -1;
        continue;
      }
      sign = 1;
    }
    if (isdigit(str[i])) {
      if (res > INT_MAX/10 || (res == INT_MAX/10 && ( str[i] - '0' > INT_MAX%10)) ) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }
      res = res*10 + str[i]-'0';
    } else{
      break;
    }

  }
  return sign* res;

}

int main ()
{
  string s1 = "  -0012a42  ";
  string s2 = "  +100";
  string s3 = "  -100  ";

  cout << "s1 = " << myAtoi(s1) << endl;
  cout << "s2 = " << myAtoi(s2) << endl;
  cout << "s3 = " << myAtoi(s3) << endl;
	return 0;
}

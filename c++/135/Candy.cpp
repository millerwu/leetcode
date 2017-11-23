//source: https://leetcode.com/problems/candy/

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
  vector<int> candyCnt(ratings.size());
  candyCnt[0] = 1;
  for (int i = 1; i < ratings.size(); ++i) {
    if (ratings[i] > ratings[i-1]) {
      candyCnt[i] = candyCnt[i-1] + 1;
    } else {
      candyCnt[i] = 1;
    }
  }
  for (int j = ratings.size()-1; j > 0 ; --j) {
    if (ratings[j] < ratings[j-1] && candyCnt[j] >= candyCnt[j-1]) {
      candyCnt[j-1] = candyCnt[j] + 1;
    }
  }
  int sum = 0;
  for (int k = 0; k < candyCnt.size(); ++k) {
    sum += candyCnt[k];
  }
  return sum;

}

int main ()
{
  vector<int> rating = { 5, 3, 1 };
  int res = candy(rating);
  cout << "res = " << res << endl;
	return 0;
}

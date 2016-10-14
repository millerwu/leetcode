//source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <iostream>
#include <vector>

using namespace std;

// use dp and greed
// use the dp array to save the result of greed
// use 2 array, save the result of left and righr.
// then get the max sum of them.

int maxProfit(vector<int>& prices) {
	int max_pft = 0;
  if (prices.size() <= 0)
  {
  	return max_pft;
  }
  int length = prices.size();
  vector<int> left_max_pft(length, 0), right_max_pft(length, 0);
  int buy_prices = INT_MAX;
  int l_max_pft = 0;
  for (int i = 0; i < length ; ++i)
  {
  	if (buy_prices > prices[i])
  	{
  		buy_prices = prices[i];
  	} else {
  		l_max_pft = max(l_max_pft, prices[i] - buy_prices);
  	}
  	left_max_pft[i] = l_max_pft;
  }
  int sell_prices = INT_MIN;
  int r_max_pft = 0;
  for (int i = length-1; i >= 0 ; --i)
  {
  	if (sell_prices < prices[i])
  	{
  		sell_prices = prices[i];
  	} else {
  		r_max_pft = max(r_max_pft, sell_prices - prices[i]);
  	}
  	right_max_pft[i] = r_max_pft;
  	if (i > 0)
  	{
  		/* code */
  		max_pft = max(max_pft, right_max_pft[i] + left_max_pft[i-1]);
  	} else {
  		max_pft = max(max_pft, right_max_pft[0]);
  	}
  }
  return max_pft;
}

int main ()
{
	vector<int> prices2 = {7, 1, 5, 3, 6, 4, 2, 10};

	int max_pft = maxProfit(prices2);
	cout << "maxProfit = " << max_pft << endl;
	return 0;
}

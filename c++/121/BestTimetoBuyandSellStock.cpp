//source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//use greedy algorithm
//Time Complexity : O(n)

int maxProfit(vector<int>& prices) {
	int max_pft = 0;
	if (prices.size() <= 0)
	{
		return max_pft;
	}
	int min_price = INT_MAX;
	for (int i = 0; i < prices.size(); ++i)
	{
		/* code */
		if (min_price >= prices[i])
		{
			min_price = prices[i];
		} else {
			int pft = prices[i] - min_price;
			max_pft = max(pft, max_pft);
		}
	}
	return max_pft;
    
}

int main ()
{
	vector<int> prices1 = {7, 6, 4, 3, 1};
	vector<int> prices2 = {7, 1, 5, 3, 6, 4};
	int max_pft = maxProfit(prices2);
	cout << "maxProfit = " << max_pft << endl;
	return 0;
}

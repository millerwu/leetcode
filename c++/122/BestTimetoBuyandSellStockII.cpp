//source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int total_pft = 0;
	if (prices.size() <= 0)
	{
		return total_pft;
	}
	int buy_price = 0;
	bool stock = false;
	for (int i = 1; i < prices.size(); ++i)
	{
		if (!stock)
		{
			if (prices[i] > prices[i-1])
			{
				buy_price = prices[i-1];
				stock = true;
			} else {
				continue;
			}
		} else {
			if (prices[i] < prices[i-1])
			{
				total_pft += prices[i-1] - buy_price;
				stock = false;
			} else {
				continue;
			}
		}
	}
	if (stock && prices[prices.size()-1] > buy_price)
	{
		total_pft += prices[prices.size()-1] - buy_price;
	}
	return total_pft;
}

int main ()
{
	vector<int> prices = {1, 2};
	vector<int> prices2 = {7, 1, 5, 3, 6, 4};

	int max_pft = maxProfit(prices);
	cout << "maxProfit = " << max_pft << endl;
	return 0;
}

package BestTimetoBuyandSellStockwithCooldown;

/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */


public class BestTimetoBuyandSellStockwithCooldown {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        int[] dp = new int[prices.length];
        for (int i = 1; i < prices.length; i++) {
            int best_profit = 0;
            dp[i] = dp[i - 1];
            for (int j = i - 1; j >= 0; j--) {
                int pri = 0;
                if (j - 2 >= 0) {
                    pri = dp[j - 2];
                }
                best_profit = Integer.max(best_profit, prices[i] - prices[j] + pri);
            }

            dp[i] = Integer.max(dp[i], best_profit);
        }
        return dp[dp.length - 1];
    }

    static public void main(String[] args) {
//        int[] input = {1, 2, 3, 0, 2};
        int[] input = {6, 1, 3, 2, 4, 7};
        BestTimetoBuyandSellStockwithCooldown bestTimetoBuyandSellStock = new BestTimetoBuyandSellStockwithCooldown();
        int res = bestTimetoBuyandSellStock.maxProfit(input);
        System.out.println(res);

    }
}

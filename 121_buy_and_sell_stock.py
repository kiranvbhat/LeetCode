# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution(object):
    # O(n) time, O(1) space
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        len_prices = len(prices)
        min_price = prices[0]
        for i in range(1, len_prices):
            price = prices[i]
            profit = price - min_price
            if profit > max_profit:
                max_profit = profit
            if price < min_price:
                min_price = price
        return max_profit

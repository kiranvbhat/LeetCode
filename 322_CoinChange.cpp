// https://leetcode.com/problems/coin-change/

class Solution {
public:
    // O(n * amount) time, bottom-up DP solution
    int coinChange(vector<int>& coins, int amount) {
        vector<int> fewestFromAmount(amount + 1);
        fewestFromAmount[0] = 0;
        for (int amt = 1; amt < amount + 1; amt++) {
            int minCoins = 100000;  // acts as infinity, since amount <= 10^4 and coins[i] >= 1
            for (int coin : coins) {
                if (amt - coin >= 0) {
                    minCoins = min(minCoins, 1 + fewestFromAmount[amt - coin]);
                }
            }
            fewestFromAmount[amt] = minCoins;
        }
        int fewest = fewestFromAmount[amount];
        return (fewest != 100000) ? fewest : -1;
    }
};

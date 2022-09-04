// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairsHelper(int n, vector<int>& numWays) {
        if (n == 0) {
            return 1;
        }
        else if (n < 0) {
            return 0;
        }
        else if (numWays[n] != 0) {
            return numWays[n];
        }
        numWays[n] = climbStairsHelper(n - 1, numWays) + climbStairsHelper(n - 2, numWays);
        return numWays[n];
    }
    
    // O(n) time, top-down / memoization
    int climbStairs(int n) {
        vector<int> numWays(n + 1);
        return climbStairsHelper(n, numWays);
    }
};

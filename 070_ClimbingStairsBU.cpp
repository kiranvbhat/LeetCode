// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    // O(n) time, bottom-up
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        int result;
        for (int i = 0; i < n - 1; i++) {
            result = one + two;
            two = one;
            one = result;
        }
        return result;
    }
};

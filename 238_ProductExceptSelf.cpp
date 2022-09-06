// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    // O(n) time, O(1) extra space
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = nums;     // "output array does not count as extra space for space complexity analysis"
        int prefix = 1;
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }
};

// https://leetcode.com/problems/two-sum/

class Solution {
public:
    // O(n) time, O(n) space
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < nums.size(); i++) {
            if (num_to_idx.count(target - nums[i]) != 0) {
                return {num_to_idx[target - nums[i]], i};
            }
            num_to_idx[nums[i]] = i;
        }
        return {};
    }
};

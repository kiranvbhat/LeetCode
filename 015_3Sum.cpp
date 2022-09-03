// https://leetcode.com/problems/3sum/submissions/

class Solution {
public:
    // O(n^2) time
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;    // skip repeats to avoid duplicate triplets
            int j = i + 1;
            int k = nums.size() - 1;
            int target = 0 - nums[i];   // nums[j] + nums[k] must equal -nums[i]
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k) {  // skip repeats to avoid duplicate triplets
                        j++;
                    }
                } 
                else if (nums[j] + nums[k] > target) k--;     // if sum is too big, decrease end
                else j++;             // if sum is too small, increase start (which increases overall sum)
            }
        }
        return triplets;
    }
};

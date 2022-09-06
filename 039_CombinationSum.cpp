// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    // Builds up sums with all unique combinations of candidates that sum to target
    void combinationSumHelper(vector<int>& candidates, int target, vector<vector<int>>& sums, 
                              vector<int>& combination, int index) {
        if (target < 0) return;
        if (target == 0) {
            sums.push_back(combination);
            return;
        }
        if (index >= candidates.size()) return;
        
        // include
        combination.push_back(candidates[index]);
        combinationSumHelper(candidates, target - candidates[index], sums, combination, index);

        // exclude
        combination.pop_back();
        combinationSumHelper(candidates, target, sums, combination, index + 1);
    }
    
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sums;
        vector<int> combination;
        combinationSumHelper(candidates, target, sums, combination, 0);
        return sums;
    }
};

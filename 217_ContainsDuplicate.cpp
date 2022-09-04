// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    // O(n) time, O(n) space
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> found;
        for (int num : nums) {
            if (found.count(num) != 0) {
                return true;
            }
            found.insert(num);
        }
        return false;
    }
};

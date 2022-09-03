// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    // O(n) time, O(1) space
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) return {start + 1, end + 1};
            else if (numbers[start] + numbers[end] > target) end--;     // if sum is too big, decrease end
            else start++;             // if sum is too small, increase start (which increases overall sum)
        }
        return {};
    }
};

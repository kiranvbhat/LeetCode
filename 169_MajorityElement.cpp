// https://leetcode.com/problems/majority-element/

class Solution {
public:
    // O(n) time, O(n) space
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (int num : nums) {
            numMap[num]++;
        }
        int largestCount = 0;
        int majorityElem = nums[0];
        for (pair<int, int> p : numMap) {
            if (p.second > largestCount) {
                largestCount = p.second;
                majorityElem = p.first;
            }
        }
        return majorityElem;
    }
    
// ------------------------------------------------------------------------------------------

    // Boyer-Moore Voting Algorithm, O(n) time, O(1) space
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int majorityElem = 0;
        for (int num : nums) {
            if (counter == 0) {
                majorityElem = num;
            }
            counter += (num == majorityElem) ? 1 : -1;
        }
        return majorityElem;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    bool isPivot(vector<int>& nums, int index) {
        if (index == 0) return false;   // prevent out of bounds errors for next line
        if (nums[index] < nums[index - 1]) return true;
        return false;
    }
    
    int findPivot(vector<int>& nums) {
        int pivot = 0;  // 0 by default, if we find a different pivot we will update this
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] <= nums[r]) return 0;    // if no rotation, immediately return 0
        while (l <= r) {
            int c = (l + r) / 2;
            if (isPivot(nums, c)) {
                pivot = c;
                break;
            }
            if (nums[c] >= nums[0]) l = c + 1;
            else r = c - 1;
        }
        return pivot;
    }
    
    int search(vector<int>& nums, int target) {
        // binary search for pivot (the start of the in order list)
        int pivot = findPivot(nums);    // index of pivot in nums
        int k = (nums.size() - pivot) % nums.size();    // pivot index
        int targetIdx = -1;
        int l = pivot;
        int r = (pivot + nums.size() - 1) % nums.size();
        
        while (true) {
            int L = (l + k) % nums.size();
            int R = (r + k) % nums.size();
            if (L > R) break;
            int c = (((L + R) / 2)  + pivot) % nums.size();     // +pivot is same as -k
            if (nums[c] == target) {
                targetIdx = c;
                break;
            }
            // if nums[c] is too small, we want to increase it
            if (nums[c] < target) {
                int orig = nums[l];
                l = (c + 1) % nums.size();
                if (nums[l] <= orig) break;     // if our calculation of l didn't increase it
            }
            // if nums[c] is too big, we want to decrease it
            else {
                int orig = nums[r];
                r = (c + nums.size() - 1) % nums.size();
                if (nums[r] >= orig) break;     // if our calculation of r didn't decrease it
            } 
        }
        return targetIdx;
    }
};

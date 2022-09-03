# https://leetcode.com/problems/binary-search/

class Solution(object):
    # O(logn) time, O(1) space
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        start_index = 0
        end_index = len(nums) - 1
        while start_index <= end_index:
            current_index = (start_index + end_index) // 2
            if nums[current_index] == target:
                return current_index
            elif nums[current_index] < target:
                start_index = current_index + 1
            else:
                end_index = current_index - 1
        return -1

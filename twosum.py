# https://leetcode.com/problems/two-sum/

class Solution(object):
    # O(n) time, O(n) space
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_to_indices = {}
        for i in range(len(nums)):
            num = nums[i]
            comp = target - num
            if comp in nums_to_indices:
                return [nums_to_indices[comp], i]
            nums_to_indices[num] = i
        return []

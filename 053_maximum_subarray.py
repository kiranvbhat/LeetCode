# https://leetcode.com/problems/maximum-subarray/

class Solution(object):
    # O(n) time, O(1) space
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = nums[0]
        curSum = 0
        for num in nums:
            if curSum < 0:
                curSum = 0
            curSum += num
            maxSum = max(curSum, maxSum)
        return maxSum

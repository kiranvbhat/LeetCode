# https://leetcode.com/problems/permutations/

class Solution(object):
    def permuteHelper(self, nums, so_far, permutations):
        if (len(nums) == 0):
            permutation = list(so_far)
            permutations.append(permutation)
            return
        numsLen = len(nums)
        for i in range(numsLen):
            num = nums.pop(i)
            so_far.append(num)
            self.permuteHelper(nums, so_far, permutations)
            nums.insert(i, num)
            so_far.pop()
            
    
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        permutations = []
        so_far = []
        self.permuteHelper(nums, so_far, permutations)
        return permutations

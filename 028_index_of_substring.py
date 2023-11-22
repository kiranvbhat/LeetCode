# https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

# Solution 1: Use string function .find()
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        # .index() throws an exception when needle isn't in haystack, .find() returns -1
        return haystack.find(needle)


# Solution 2: Manually loop over haystack to find needle index
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i+len(needle)] == needle:
                return i
        if haystack == needle:
            return 0
        return -1

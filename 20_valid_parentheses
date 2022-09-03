# https://leetcode.com/problems/valid-parentheses/

class Solution(object):
    # O(n^2) time, O(1) space
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        while True:
            if (s == ""):
                return True
            
            # Get the index of the brackets
            index = s.find("()")
            if index == -1:
                index = s.find("{}")
            if index == -1:
                index = s.find("[]")
            
            # If we found brackets, remove them
            if index != -1:
                s = s[:index] + s[index + 2:]
            else:
                return False

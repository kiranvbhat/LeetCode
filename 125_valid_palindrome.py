# https://leetcode.com/problems/valid-palindrome/

class Solution(object):
    # O(n) time
    def isPalindrome(self, s):
        s = "".join(ch.lower() for ch in s if ch.isalnum())
        return s == s[::-1]

// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    // O(n) time
    int longestPalindrome(string s) {
        unordered_map<char, int> charMap;
        for (char ch : s) {
            charMap[ch]++;
        }
        
        int palindromeLength = 0;
        bool oddCountExists = false;
        for (pair<char, int> p : charMap) {
            palindromeLength += p.second;
            if (p.second % 2 != 0) {
                palindromeLength--;
                oddCountExists = true;
            }
        }
        if (oddCountExists) palindromeLength++;    // if there is an odd count of any letter, add 1 to length
        return palindromeLength;
    }
};

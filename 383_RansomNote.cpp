// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    // O(n) time, O(n) space
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charMap;
        for (char ch : magazine) {
            charMap[ch]++;
        }
        for (char ch : ransomNote) {
            if (charMap[ch] < 1) {
                return false;
            }
            charMap[ch]--;
        }
        return true;
    }
};

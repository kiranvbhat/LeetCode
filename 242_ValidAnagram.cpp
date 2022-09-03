// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    // O(n) time, O(n) space
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        for (char c : t) {
            count[c]--;
        }
        for (pair<char, int> p : count) {
            if (p.second != 0) {
                return false;
            }
        }
        return true;
    }
};

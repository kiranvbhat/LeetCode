// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    // solution 1
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substring;
        int start = 0;
        int maxLength = 0;
        
        for (int end = 0; end < s.length(); end++) {
            while (substring.count(s[end]) != 0) {
                substring.erase(s[start]);
                start++;
            }
            substring.insert(s[end]);
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
    
// ------------------------------------------------------------------------------------------
    
    // solution 2
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

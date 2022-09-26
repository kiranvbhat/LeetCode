// https://leetcode.com/problems/word-break/

class Solution {
public:
    // O(s.length() * wordDict.size()) time
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true;
        for (int k = s.length() - 1; k >= 0; k--) {
            for (string word : wordDict) {
                if (k + word.length() > s.length()) continue;
                string cur = s.substr(k, word.length());
                if (cur == word) {
                    dp[k] = dp[k + word.length()];
                    if (dp[k]) break;
                }
            }  
        }
        return dp[0];
    }
};

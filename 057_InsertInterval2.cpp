// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    // From LeetCode 56: Merge Intervals. O(n) time since sorted order already guaranteed.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        vector<int> bin = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            int binStart = bin[0];
            int binEnd = bin[1];
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            
            if (curStart <= binEnd) {       // if cur interval overlaps with bin, expand bin
                bin[0] = min(binStart, curStart);
                bin[1] = max(binEnd, curEnd);
            } else {
                merged.push_back(bin);
                bin = intervals[i];
            }
        }
        merged.push_back(bin);
        return merged;
    }
    
    // O(n) time
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // first insert interval at correct position
        vector<vector<int>> output;
        bool newIntervalInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0] && !newIntervalInserted) {
                output.push_back(newInterval);
                newIntervalInserted = true;
            }
            output.push_back(intervals[i]);
        }
        if (!newIntervalInserted) output.push_back(newInterval);
        
        // then perform merge
        return merge(output);
    }
};

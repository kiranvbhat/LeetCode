// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    // O(nlogn) time
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        
        // build up output vector with merged intervals
        vector<vector<int>> output;
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
                output.push_back(bin);
                bin = intervals[i];
            }
        }
        output.push_back(bin);
        return output;
    }
};

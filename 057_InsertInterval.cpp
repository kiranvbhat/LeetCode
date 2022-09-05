// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    bool overlaps(vector<int> one, vector<int> two) {
        if (one[0] <= two[0] && two[0] <= one[1]) {
            return true;
        }
        if (one[0] <= two[1] && two[1] <= one[1]) {
            return true;
        }
        if (two[0] <= one[0] && one[0] <= two[1]) {
            return true;
        }
        if (two[0] <= one[1] && one[1] <= two[1]) {
            return true;
        } 
        return false;
    }
    
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        vector<vector<int>> ivs;
        int start = newInterval[0];
        int end = newInterval[1];
        int stage = 0;  // 0 for pre-insert, 1 for inserting, 2 for post-insert
        
        for (int i = 0; i < intervals.size(); i++) {
            // if theres an overlap, update start/end
            if (overlaps({start, end}, intervals[i])) {
                stage = 1;
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
            else {
                if (stage == 1) {
                    ivs.push_back({start, end});
                    stage = 2;
                }
                ivs.push_back(intervals[i]);
            }
        }
        
        // edge case: no overlap occurred
        if (stage == 0) {
            ivs = {};
            int i = 0;
            while (i < intervals.size() && start > intervals[i][1]) {
                ivs.push_back(intervals[i]);
                i++;
            }
            ivs.push_back(newInterval);
            for (int j = i; j < intervals.size(); j++) {
                ivs.push_back(intervals[j]);
            }
        }
        
        // edge case: we only had a single item in intervals, and overlap occurred
        if (stage == 1) {
            ivs.push_back({start, end});
        }
        return ivs;
    }
};

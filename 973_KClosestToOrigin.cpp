// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:    
    // O(nlogk) time
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for (vector<int> point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, x, y});  // highest dist is highest priority
            if (pq.size() > k) {
                pq.pop();   // pop highest dist point
            }
        }
        vector<vector<int>> topK;
        for (int i = 0; i < k; i++) {
            vector<int> point = pq.top();
            topK.push_back({point[1], point[2]});
            pq.pop();
        }
        return topK;
    }
};

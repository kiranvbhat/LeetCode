// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, pair<int, int>& tile) {
        return !(tile.first < 0 || tile.first >= grid.size() || tile.second < 0 || tile.second >= grid[0].size() || grid[tile.first][tile.second] != 1);
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS
        queue<pair<int, int>> q;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2) q.push({row, col});
            }
        }
        
        int minutes = 0;
        int xs[] = {0, 1, 0, -1};
        int ys[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            bool incrementMinutes = false;
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                pair<int, int> cur = q.front();
                if (grid[cur.first][cur.second] == 1) incrementMinutes = true;   // if we have at least 1 fresh orange in the queue
                q.pop();
                grid[cur.first][cur.second] = 2;
                for (int t = 0; t < 4; t++) {
                    pair<int, int> neighbor = {cur.first + ys[t], cur.second + xs[t]};
                    if (isValid(grid, neighbor)) q.push(neighbor);
                }
            }
            if (incrementMinutes) minutes++;    // only increment minutes when we have at least 1 fresh orange in the queue
        }
        
        // if theres any fresh oranges left, return -1 (not all oranges rotted)
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) return -1;
            }
        }
        
        // otherwise, return the number of minutes it took to rot all the oranges
        return minutes;
    }
};

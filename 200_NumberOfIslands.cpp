// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void discoverIsland(vector<vector<char>>& grid, int row, int col) {
        // if out of bounds, return
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        
        // if we arent on a 1, return
        if (grid[row][col] != '1') return;
        
        // since we are on a 1, change it to a 2 to mark visited
        grid[row][col] = '2';
        
        // explore all 4-directions
        discoverIsland(grid, row - 1, col);  // up
        discoverIsland(grid, row, col + 1);  // right
        discoverIsland(grid, row + 1, col);  // down
        discoverIsland(grid, row, col - 1);  // left
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int numIs = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    numIs++;
                    discoverIsland(grid, row, col);  // mark all 1s on this island as 2s (visited)
                }
            }
        }
        return numIs;
    }
};

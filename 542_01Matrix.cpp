// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    bool isValid(pair<int, int> cell, int numRows, int numCols) {
        return !(cell.first < 0 || cell.first >= numRows || cell.second < 0 || cell.second >= numCols);
    }
    
    // O(n + m) time, O(m * n) space
    // Space efficient since extra visited matrix/set not used in this solution
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();
        vector<vector<int>> distMat(numRows, vector<int>(numCols, -1));   // initialized to -1 since not visited
        queue<pair<int, int>> q;
        
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (mat[row][col] == 0) {
                    distMat[row][col] = 0;
                    q.push({row, col});
                }
            }
        }
        
        const int x[] = {0, 1, 0, -1};
        const int y[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {       // loop thru potential neighbors
                pair<int, int> neighbor = {cur.first + x[i], cur.second + y[i]};
                
                // if neighbor is valid and unvisited
                if (isValid(neighbor, numRows, numCols) && distMat[neighbor.first][neighbor.second] == -1) {
                    distMat[neighbor.first][neighbor.second] = distMat[cur.first][cur.second] + 1;
                    q.push(neighbor);
                }
            }
        }
        return distMat;
    }
};

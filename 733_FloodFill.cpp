// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int color, int starting_color) {
        int image_height = image.size();
        int image_width = image[0].size();
        
        // exit if the pixel is out of bounds
        if (sr > image_height - 1 || sr < 0 || sc > image_width - 1 || sc < 0) {
            return;
        }
        
        // exit if the pixel is not the same color as starting color
        else if (image[sr][sc] != starting_color) {
            return;
        }
        
        // update pixel color, since we know we are on a valid pixel
        image[sr][sc] = color;
        
        // now flood any pixels that are 4-directionally connected
        floodFillHelper(image, sr - 1, sc, color, starting_color);
        floodFillHelper(image, sr + 1, sc, color, starting_color);
        floodFillHelper(image, sr, sc - 1, color, starting_color);
        floodFillHelper(image, sr, sc + 1, color, starting_color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int starting_color = image[sr][sc];
        if (starting_color == color) {  // we don't need to make any changes to image in this case
            return image;
        }
        floodFillHelper(image, sr, sc, color, starting_color);
        return image;
    }
};

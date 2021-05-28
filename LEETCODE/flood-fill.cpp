#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flood-fill/
/**
  * A simple DFS will solve this.
  * Just check if newColor != oldColor
 */
class Solution {
public:
    vector<vector<int>> steps = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };
    
    void combineSolver(vector<vector<int>> &image, int i, int j, int newColor, int oldColor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
            return;
        
        if (image[i][j] != oldColor)
            return;
        
        image[i][j] = newColor;
        for (int k = 0; k < 4; k++)
            combineSolver(image, i + steps[k][0], j + steps[k][1], newColor, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            combineSolver(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
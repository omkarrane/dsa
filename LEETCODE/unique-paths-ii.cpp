#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/
/**
 * we can recursively solve this question while memoizing the overlapping subproblems
 */
class Solution {
public:
    vector<vector<int>> dp;
    
    int combineSolver(vector<vector<int>> &grid, int i, int j) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        
        if (grid[i][j] == 1)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = combineSolver(grid, i + 1, j) + combineSolver(grid, i, j + 1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        return combineSolver(obstacleGrid, 0, 0);
    }
};
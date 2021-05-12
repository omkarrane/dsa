#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-islands/
/**
  * We can just use a simple dfs algorithm for every land cell.
  * Once a cell is visited, we can mark it as '0' or '-1' so as to avoid visiting it again
  * Now, once our dfs algorithm is set, we traverse through the grid and if we encounter a land cell, we increment the islands variable and call a dfs for this island
 */
class Solution {
public:
    vector<vector<int>> steps = {
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        
        if (grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
            dfs(grid, i + steps[k][0], j + steps[k][1]);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-falling-path-sum/
/**
 * here, we choose the best choice available for every available tile
 * for this, we can use the following recurrence relation
 * T(i,j) = min(T(i-1,j), T(i-1,j-1), T(i-1,j+1)) + cost(i,j)
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int mn = matrix[i - 1][j];
                if (j > 0)
                    mn = min(mn, matrix[i - 1][j - 1]);
                if (j + 1 < matrix.size())
                    mn = min(mn, matrix[i - 1][j + 1]);
                
                matrix[i][j] += mn;
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++)
            ans = min(ans, matrix[matrix.size() - 1][i]);
        
        return ans;
    }
};
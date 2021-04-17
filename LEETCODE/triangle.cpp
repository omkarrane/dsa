#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/triangle/
/**
 * as optimal sub-structure and overlapping subproblems can be clearly viewed from this, we can just solve this using dp
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for (int i = n - 2; i >= 0; i--) {
            int k = triangle[i + 1].size();
            for (int j = 0; j < k - 1; j++) {
                int temp = min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                triangle[i][j] += temp;
            }
        }
        
        return triangle[0][0];
    }
};
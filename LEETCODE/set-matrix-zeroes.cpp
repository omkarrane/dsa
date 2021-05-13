#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/
/**
  * We use the first column and first row as sentinels for solving this.
  * Also, we need to take care of conditions where the first row and column itself contains 0.
  * We achieve this by using 2 boolean variables.
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool isCol = false;
        bool isRow = false;
        
        for (int i = 0; i < n; i++)
            if (matrix[i][0] == 0)
                isCol = true;
        
        for (int j = 0; j < m; j++)
            if (matrix[0][j] == 0)
                isRow = true;
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if (isRow)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        
        if (isCol)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};
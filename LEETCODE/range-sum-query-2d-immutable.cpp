#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/range-sum-query-2d-immutable/
/**
  * This can be thought of as a prefix sum but on a matrix level
 */
class NumMatrix {
public:
    vector<vector<long long>> arr;
    int n = 0;
    int m = 0;
    
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        arr = vector<vector<long long>>(n, vector<long long>(m, 0ll));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = matrix[i][j];
            }
        }
        
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                arr[i][j] += arr[i - 1][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                arr[i][j] += arr[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long sum = arr[row2][col2];
        if (row1 > 0)
            sum -= arr[row1 - 1][col2];
        if (col1 > 0)
            sum -= arr[row2][col1 - 1];
        if (row1 > 0 && col1 > 0)
            sum += arr[row1 - 1][col1 - 1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
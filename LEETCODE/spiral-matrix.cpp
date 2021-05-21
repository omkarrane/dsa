#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/
/**
  * We can just simulate the matrix according to the directions.
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int colStart = 0;
        int rowStart = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        vector<int> ans;
        
        int dir = 1;
        while (colStart <= colEnd && rowStart <= rowEnd) {
            if (dir == 1) {
                int temp = colStart;
                while (temp <= colEnd) {
                    ans.push_back(matrix[rowStart][temp++]);
                }
                
                rowStart++;
                dir = 2;
            }
            else if (dir == 2) {
                int temp = rowStart;
                while (temp <= rowEnd) {
                    ans.push_back(matrix[temp++][colEnd]);
                }
                
                colEnd--;
                dir = 3;
            }
            else if (dir == 3) {
                int temp = colEnd;
                while (temp >= colStart) {
                    ans.push_back(matrix[rowEnd][temp--]);
                }
                
                rowEnd--;
                dir = 4;
            }
            else if (dir == 4) {
                int temp = rowEnd;
                while (temp >= rowStart) {
                    ans.push_back(matrix[temp--][colStart]);
                }
                
                colStart++;
                dir = 1;
            }
        }
        
        return ans;
    }
};
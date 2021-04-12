#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/score-after-flipping-matrix/
/**
 * one observation is that if the msb is 1, then no need to check for the rest of the bits for the rows
 * because, 2^1 > 2^(i-1) + 2^(i-2)...
 * now for every col, just count the number of 1s and 0s..if the number of 0s is greater, then flip them
 */
class Solution {
public:
    int getNum(vector<int> &arr) {
        int power = arr.size() - 1;
        int current = 0;
        int num = 0;
        while (current < arr.size()) {
            if (arr[current] == 1)
                num += pow(2, power);
            power--;
            current++;
        }
        
        return num;
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
        for (int i = 0; i < row; i++) {
            if (A[i][0] == 1)
                continue;
            else {
                for (int j = 0; j < col; j++)
                    A[i][j] ^= 1;
            }
        }
        
        for (int j = 0; j < col; j++) {
            int ones = 0, zeroes = 0;
            for (int i = 0; i < row; i++) {
                if (A[i][j] == 0)
                    zeroes++;
                else
                    ones++;
            }
            
            if (ones < zeroes) {
                for (int i = 0; i < row; i++)
                    A[i][j] ^= 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < row; i++) {
            ans += getNum(A[i]);
        }
        
        return ans;
    }
};
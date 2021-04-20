#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/knight-probability-in-chessboard/
/**
 * we first try to implement the recursive solution for this and observe that there are overlapping sub-problems
 * in order to define the dp state, we see that there are 3 criterias based on which we set the recursive relation - r, c, K
 * hence, we define a 3d dp for memoization
 */
class Solution {
public:
    vector<vector<int>> dir = {{1,2}, {2,1}, {1,-2}, {2,-1}, {-1,-2}, {-1,2}, {-2,1}, {-2,-1}};
    vector<vector<vector<double>>> dp;
    
    double combineHelper(int n, int k, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= n)
            return 0;
        
        if (k == 0)
            return 1;
        
        if (dp[k][r][c] != -1)
            return dp[k][r][c];
        
        double current = 0;
        for (int i = 0; i < 8; i++) {
            current += 0.125 * combineHelper(n, k-1, r - dir[i][0], c - dir[i][1]);
        }
        
        return dp[k][r][c] = current;
    }
    
    double knightProbability(int N, int K, int r, int c) {
        dp = vector<vector<vector<double>>>(K + 1);
        for (int i = 0; i <= K; i++) {
            dp[i] = vector<vector<double>>(N);
            for (int j = 0; j < N; j++) {
                dp[i][j] = vector<double>(N, -1);
            }
        }
        return combineHelper(N, K, r, c);
    }
};
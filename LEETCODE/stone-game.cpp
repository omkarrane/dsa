#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/stone-game/
/**
 * we can just try all possibilities and memoize the intermediate solutions
 */
class Solution {
public:
    vector<vector<int>> dp;
    
    bool combineSolver(vector<int> &piles, int alex, int lee, int i, int j) {
        if (i > j)
            return alex > lee;
        
        if (dp[i][j] != -1)
            return dp[i][j] == 1;
        
        bool a = combineSolver(piles, alex + piles[i], lee + piles[j], i + 1, j - 1);
        bool b = combineSolver(piles, alex + piles[j], lee + piles[i], i + 1, j - 1);
        bool c = false, d = false;
        if (j - i > 2) {
            c = combineSolver(piles, alex + piles[i], lee + piles[i + 1], i + 2, j);
            d = combineSolver(piles, alex + piles[j], lee + piles[j - 1], i, j - 2);
        }
        
        return dp[i][j] = a || b || c || d;
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return combineSolver(piles, 0, 0, 0, n - 1);
    }
};
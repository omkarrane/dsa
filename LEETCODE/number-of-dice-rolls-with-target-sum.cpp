#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
/**
 * our dp state can be defined as dices left + currentSum. hence, a 2d dp is needed
 */
class Solution {
public:
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp;
    
    long long combineHelper(int dices, int faces, int targetSum, int currentSum) {
        if (currentSum == targetSum && dices == 0)
            return dp[dices][currentSum] = 1ll;
        
        if (dices == 0 || currentSum > targetSum)
            return 0ll;
        
        if (dp[dices][currentSum] != -1ll)
            return dp[dices][currentSum];
        
        long long current = 0ll;
        for (int i = 1; i <= faces; i++) {
            current += combineHelper(dices - 1, faces, targetSum, currentSum + i);
            current %= mod;
        }
        
        return dp[dices][currentSum] = current % mod;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        dp = vector<vector<long long>>(d + 1, vector<long long>(target + 1, -1ll));
        return combineHelper(d, f, target, 0);
    }
};
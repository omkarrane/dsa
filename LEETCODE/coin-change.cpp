#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change/
/**
 * here we can see that the following recurrence relation can give us the correct answer
 * T(n) = min(T(n - ci)) + 1, where ci are all the denominations of coins available 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            dp[i] = amount + 1;
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        
        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};
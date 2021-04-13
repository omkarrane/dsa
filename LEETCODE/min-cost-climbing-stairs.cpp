#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-cost-climbing-stairs/
/**
 * by observation, we can see that this qualifies a dp solution as there are clear optimal substructure and overlapping subproblems available
 * recurrence relation T(i) = cost(n) + min(T(i - 1), T(i - 2))
 * for this, we just add a '0' to the cost of the topmost stair and use the above relation to get the answer
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size() + 1;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = cost[0];
        
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + cost[i - 1];
            dp[i] = min(dp[i], dp[i - 2] + cost[i - 1]);
        }
        
        return dp[n - 1];
    }
};
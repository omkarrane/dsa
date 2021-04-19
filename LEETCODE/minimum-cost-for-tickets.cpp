#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-for-tickets/
/**
 * as for every given day there are 3 possibilities which we can express using recursion
 * also we can apply dp(memoization) for overlapping sub-problems
 */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n - 1];
        vector<int> dp(lastDay + 1, 1e9);
        dp[lastDay] = *min_element(costs.begin(), costs.end());
        
        for (int i = n - 2; i >= 0; i--) {
            int nextDay = upper_bound(days.begin(), days.end(), days[i]) - days.begin();
            dp[days[i]] = min(dp[days[i]], dp[days[nextDay]] + costs[0]);
            if (days[i] + 7 <= lastDay) {
                int nextPossibleDay = upper_bound(days.begin(), days.end(), days[i] + 6) - days.begin();
                dp[days[i]] = min(dp[days[i]], dp[days[nextPossibleDay]] + costs[1]);
            }
            else {
                dp[days[i]] = min(dp[days[i]], costs[1]);
            }
            
            if (days[i] + 30 <= lastDay) {
                int nextPossibleDay = upper_bound(days.begin(), days.end(), days[i] + 29) - days.begin();
                dp[days[i]] = min(dp[days[i]], dp[days[nextPossibleDay]] + costs[2]);
            }
            else {
                dp[days[i]] = min(dp[days[i]], costs[2]);
            }
        }
        
        return dp[days[0]];
    }
};
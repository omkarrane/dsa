#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
/**
  * We can greedily check for every consecutive pair if it gives any sort of profit.
  * If yes, then we add it to the answer.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int curr = prices[i + 1] - prices[i];
            if (curr > 0)
                ans += curr;
        }
        
        return ans;
    }
};
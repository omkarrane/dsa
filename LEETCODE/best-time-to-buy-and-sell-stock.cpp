#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
/**
 * we can see that we need to find 2 values with biggest positive difference
 * hence, we can use a prefix sum where difference between 2 days is stored and find the maxSum then
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prefix(prices.size(), 0);
        for (int i = 1; i < prefix.size(); i++)
            prefix[i] = prices[i] - prices[i - 1];
        
        int mx = 0;
        int curr = 0;
        for (int i = 0; i < prefix.size(); i++) {
            curr += prefix[i];
            
            if (curr < 0)
                curr = 0;
            
            mx = max(mx, curr);
        }
        
        return mx;
    }
};
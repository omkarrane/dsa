#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = 0;
        int p = n / 3;
        for (int i = 1; i <= p; i++)
            ans += piles[n - (i * 2)];
        
        return ans;
    }
};
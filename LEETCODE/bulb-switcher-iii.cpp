#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/bulb-switcher-iii/
/**
 * this problem is similar to max-chunks-to-make-array-sorted
 * it can be solved in 2 ways
 * one is to calculate the prefixSum and sum of n natural numbers formular and see if its same
 * other is to check if the index and max found so far matches
 */
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        long long prefixSum = 0ll;
        int n = light.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            long long correct = (long long) (i + 1) * (long long) (i + 2) / 2ll;
            prefixSum += (long long) light[i];
            if (correct == prefixSum)
                ans++;
        }
        
        return ans;
    }

    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        int ans = 0;
        int mx = 0;
        
        for (int i = 0; i < n; i++) {
            mx = max(mx, light[i]);
            if (mx == i + 1)
                ans++;
        }
        
        return ans;
    }
};
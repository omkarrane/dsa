#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long currentSum = 0, currentProduct = 0;
        long long n = nums.size();
        currentSum = n * (n + 1) / 2;
        currentProduct = n * (n + 1) * ((2 * n) + 1) / 6;
        
        for (int i = 0; i < n; i++) {
            currentSum -= (long long) nums[i];
            currentProduct -= ((long long) nums[i] * (long long) nums[i]);
        }
        
        int missing = (currentSum + (currentProduct / currentSum)) / 2;
        int repeat = missing - currentSum;
        
        vector<int> ans = {repeat, missing};
        return ans;
    }
};
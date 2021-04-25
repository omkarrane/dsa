#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-digits-in-base-k/
class Solution {
public:
    void getNumber(vector<int> &arr, int n, int k) {
        if (n < k) {
            arr.push_back(n);
            return;
        }
        
        int rem = n % k;
        getNumber(arr, n / k, k);
        arr.push_back(rem);
    }
    
    int sumBase(int n, int k) {
        vector<int> arr;
        getNumber(arr, n, k);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            ans += arr[i];
        
        return ans;
    }
};
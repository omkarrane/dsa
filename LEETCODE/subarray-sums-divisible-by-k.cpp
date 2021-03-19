#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sums-divisible-by-k/
/**
 * First calculate the prefix sum of given array
 * then store the count of mod K values
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefixSum(n);
        prefixSum[0] = A[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + A[i];
        
        vector<int> hash(K, 0);
        hash[0] = 1;
        for (int i = 0; i < n; i++) {
            int key = (prefixSum[i] % K + K) % K;
            hash[key]++;
        }
        
        int ans = 0;
        for (int i = 0; i < K; i++) {
            ans += hash[i] * (hash[i] - 1) / 2;
        }
        
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m1;
        int n = A.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = A[i] + B[j];
                if (m1.find(sum) == m1.end())
                    m1[sum] = 0;
                m1[sum]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = C[i] + D[j];
                if (m1.find(-sum) != m1.end()) {
                    ans += m1[-sum];
                }
            }
        }
        
        return ans;
    }
};
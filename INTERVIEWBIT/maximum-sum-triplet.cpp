#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/maximum-sum-triplet/
int solve(vector<int> &A) {
    int maxSum = 0;
    int n = A.size();
    
    vector<int> suffix(n);
    suffix[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], A[i]);
        
    set<int> s;
    for (int i = 1; i < n - 1; i++) {
        s.insert(A[i - 1]);
        auto temp = s.lower_bound(A[i]);
        --temp;
        int max1 = *temp;
        
        int max2 = suffix[i + 1];
        if (max1 > 0 && A[i] > max1 && max2 > A[i]) {
            int currSum = A[i] + max1 + max2;
            maxSum = max(maxSum, currSum);
        }
    }
    
    return maxSum;
}

#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/pick-from-both-sides/
int solve(vector<int> &A, int B) {
    vector<int> C;
    int n = A.size();
    for (int i = n - B; i < n; i++)
        C.push_back(A[i]);
    
    for (int i = 0; i < B; i++)
        C.push_back(A[i]);
    
    int maxSum = 0;
    for (int i = 0; i < B; i++)
        maxSum += C[i];
    
    int currSum = maxSum;
    for (int i = B; i < C.size(); i++) {
        currSum = currSum - C[i - B] + C[i];
        maxSum = max(currSum, maxSum);
    }
    
    return maxSum;
}

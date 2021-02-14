#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
int coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = ans + max(abs(A[i - 1] - A[i]), abs(B[i - 1] - B[i]));
    }
    
    return ans;
}

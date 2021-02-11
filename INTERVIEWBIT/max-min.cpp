#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/
int solve(vector<int> &A) {
    int m = INT_MIN, n = INT_MAX;
    for (int i = 0; i < A.size(); i++) {
        m = max(m, A[i]);
        n = min(n, A[i]);
    }
    
    return m + n;
}

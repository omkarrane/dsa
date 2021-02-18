#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/min-xor-value/
int findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int mn = INT_MAX;
    for (int i = 1; i < A.size(); i++) {
        int a = A[i] ^ A[i - 1];
        mn = min(mn, a);
    }
    
    return mn;
}

#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/xor-ing-the-subarrays/
int solve(vector<int> &A) {
    int ans = 0;
    int n = A.size();
    for (int i = 0; i < A.size(); i++) {
        int a = i + 1;
        int b = n - i;
        if (a % 2 == 1 && b % 2 == 1)
            ans ^= A[i];
    }
    
    return ans;
}

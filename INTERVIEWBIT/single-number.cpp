#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/single-number/
int singleNumber(const vector<int> &A) {
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
        ans ^= A[i];
    
    return ans;
}
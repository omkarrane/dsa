#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/smaller-or-equal-elements/
int solve(vector<int> &A, int B) {
    int ans = 0;
    int low = 0, high = A.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] <= B) {
            ans = mid + 1;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    return ans;
}

#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/search-in-bitonic-array/
int solve(vector<int> &A, int B) {
    int n = A.size();
    int bitonicPoint = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            bitonicPoint = mid;
            break;
        }
        else if (A[mid] > A[mid - 1]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    int ans = -1;
    if (A[bitonicPoint] >= B) {
        ans = lower_bound(A.begin(), A.begin() + bitonicPoint + 1, B) - A.begin();
        if (A[ans] != B)
            return -1;
    }
    else {
        ans = lower_bound(A.begin() + bitonicPoint, A.end(), B, std::greater<int>()) - A.begin();
        if (A[ans] != B)
            return -1;
    }
    
    return ans;
}

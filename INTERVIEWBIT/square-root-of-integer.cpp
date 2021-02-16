#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/square-root-of-integer/
int sqrt(int A) {
    int low = 0, high = A / 2;
    int ans = 1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if ((mid * mid) == A)
            return mid;
        else if ((mid * mid) < A) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return ans;
}

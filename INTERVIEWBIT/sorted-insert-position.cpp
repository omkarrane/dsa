#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/sorted-insert-position/
int searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int low = 0, high = A.size() - 1;
    int ans;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B) {
            ans = mid + 1;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    return ans;
}

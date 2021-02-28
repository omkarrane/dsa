#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        if (A.size() == 1)
            return A[0];
        
        int low = 0;
        int high = A.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0 && A[mid] != A[mid + 1])
                return A[mid];
            else if (mid == A.size() - 1 && A[mid] != A[mid - 1])
                return A[mid];
            else if (A[mid] != A[mid - 1] && A[mid] != A[mid + 1])
                return A[mid];
            else if (mid % 2 == 0) {
                if (A[mid] == A[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else {
                if (A[mid] == A[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return -1;
    }
};
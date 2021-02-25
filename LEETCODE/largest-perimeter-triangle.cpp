#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-perimeter-triangle/
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        for (int i = n; i >= 3; i--) {
            int a = A[i - 1], b = A[i - 2], c = A[i - 3];
            if ((b + c) <= a)
                continue;
            return a + b + c;
        }
        
        return 0;
    }
};
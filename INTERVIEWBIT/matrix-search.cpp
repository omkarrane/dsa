#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/matrix-search/
int searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int low = 0;
    int high = n * m;
    high--;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int curr = A[mid / m][mid % m];
        if (curr == B)
            return 1;
        else if (curr < B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return 0;
}

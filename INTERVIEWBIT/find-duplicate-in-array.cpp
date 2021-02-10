#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/find-duplicate-in-array/
int repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = A[i];
        
    for (int i = 0; i < n; i++) {
        if (abs(temp[i]) - 1 < n && temp[abs(temp[i]) - 1] < 0)
            return abs(temp[i]);
        temp[abs(temp[i]) - 1] = -temp[abs(temp[i]) - 1];
    }
    
    return -1;
}

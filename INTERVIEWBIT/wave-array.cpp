#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/wave-array/
vector<int> wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int size = A.size();
    if (size % 2 != 0)
        size--;
    for (int i = 0; i < size; i += 2)
        swap(A[i], A[i + 1]);
        
    return A;
}

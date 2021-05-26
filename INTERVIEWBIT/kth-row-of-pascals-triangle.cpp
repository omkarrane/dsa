#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
vector<int> Solution::getRow(int A) {
    if (A == 0) {
        return vector<int>(1, 1);
    }
    vector<int> d = {1, 1};
    
    for (int i = 2; i <= A; i++) {
        for (int j = d.size() - 1; j > 0; j--) {
            d[j] += d[j - 1];
        }
        
        d.push_back(1);
    }
    
    return d;
}

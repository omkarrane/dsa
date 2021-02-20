#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/single-number-ii/
int singleNumber(const vector<int> &A) {
    int num = 0;
    for (int j = 0; j < 32; j++) {
        int ones = 0;
        for (int i = 0; i < A.size(); i++) {
            if ((A[i] & (1 << j)) > 0)
                ones++;
        }
        
        if (ones % 3 != 0)
            num |= (1 << j);
    }
    
    return num;
}

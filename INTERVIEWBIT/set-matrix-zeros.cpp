#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/set-matrix-zeros/
void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = A[0].size();
    vector<int> rows, cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }
    
    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < cols.size(); j++) {
            A[i][j] = 0;
        }
    }
}

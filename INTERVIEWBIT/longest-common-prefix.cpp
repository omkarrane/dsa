#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/longest-common-prefix/
string longestCommonPrefix(vector<string> &A) {
    string ans = "";
    int n = A.size();
    for (int j = 0; j < A[0].size(); j++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
               if (j == A[i].size() || A[i][j] != A[0][j]) {
                   flag = false;
                   break;
               }
        }
        
        if (flag)
            ans.push_back(A[0][j]);
        else
            break;
    }
    
    return ans;
}

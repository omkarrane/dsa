#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/pascal-triangle/
vector<vector<int> > solve(int A) {
    if (A == 0) {
        vector<vector<int>> temp;
        return temp;
    }
    else if (A == 1) {
        vector<vector<int>> temp = {
            {1}
        };
        return temp;
    }
    else if (A == 2) {
        vector<vector<int>> temp = {
            {1},
            {1, 1}
        };
        return temp;
    }
    vector<vector<int>> ans = {
        {1},
        {1, 1}
    };
    
    for (int i = 2; i < A; i++) {
        vector<int> row;
        for (int j = 0; j < ans[i - 1].size(); j++) {
            if (j == 0) {
                row.push_back(1);
                continue;
            }
            
            row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        row.push_back(1);
        ans.push_back(row);
    }
    
    return ans;
}

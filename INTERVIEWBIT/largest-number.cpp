#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/largest-number/
bool compare(string a, string b) {
    return (a + b) > (b + a);
}

string largestNumber(const vector<int> &A) {
    vector<string> ans;
    bool allZero = true;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != 0)
            allZero = false;
        ans.push_back(to_string(A[i]));   
    }
    
    if (allZero)
        return "0";
    
    string res = "";
    sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < ans.size(); i++)
        res.append(ans[i]);
    
    return res;
}

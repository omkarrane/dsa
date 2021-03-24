#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<vector<int>>> hash;
        int n = points.size();
        
        for (int i = 0; i < n; i++) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            hash[dist].push_back(points[i]);
        }
        
        vector<vector<int>> ans;
        for (auto i : hash) {
            for (int j = 0; j < i.second.size(); j++) {
                if (ans.size() == k)
                    return ans;
                ans.push_back(i.second[j]);
            }
        }
        
        return ans;
    }
};
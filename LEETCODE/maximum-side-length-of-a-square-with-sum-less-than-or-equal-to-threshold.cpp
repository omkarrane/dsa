#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
class Solution {
public:
    bool isPossible(vector<vector<int>> &prefix, int k, int threshold) {
        for (int i = k - 1; i < prefix.size(); i++) {
            for (int j = k - 1; j < prefix[i].size(); j++) {
                int current = prefix[i][j];
                if (i - k >= 0)
                    current -= prefix[i - k][j];
                if (j - k >= 0)
                    current -= prefix[i][j - k];
                if (i - k >= 0 && j - k >= 0)
                    current += prefix[i - k][j - k];
                
                if (current <= threshold)
                    return true;
            }
        }

        return false;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> prefix = mat;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 1; j < mat[i].size(); j++) {
                prefix[i][j] += prefix[i][j - 1];
            }
        }

        for (int i = 1; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                prefix[i][j] += prefix[i - 1][j ];
            }
        }
        
        int low = 1;
        int high = min(mat.size(), mat[0].size());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool possible = isPossible(prefix, mid, threshold);
            
            if (possible) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-chunks-to-make-sorted/
/**
 * We keep a track of the correct index of the max element we have encountered
 * This helps us to find the largest element in a particular chunk and then we count such chunks
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, curr = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            curr = max(curr, arr[i]);
            
            if (curr == i) {
                ans++;
                curr = INT_MIN;
            }
        }
        
        return ans;
    }
};
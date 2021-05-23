#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game/
/**
  * We can either solve this using dynamic programming which would take O(n^2) time complexity.
  * Another approach to this would be calculating greedily.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1)
            return true;
        
        int curr = 0;
        
        for (int i = 0; i < n - 1; i++) {
            curr = max(curr, nums[i]);
            
            if (curr == 0)
                return false;
            
            curr--;
        }
        
        return curr >= 0;
    }
};
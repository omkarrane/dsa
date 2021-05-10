#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shuffle-an-array/
class Solution {
public:
    vector<int> arr;
    
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = arr.size();
        vector<bool> used(n, false);
        vector<int> nArr = arr;
        
        for (int i = 0; i < n; i++) {
            swap(nArr[i], nArr[rand() % n]);
        }
        
        return nArr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
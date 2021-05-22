#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/3sum/
/**
  * We can use a modified version of 2Sum here.
  * The modified version would find the sum = nums[i] for every element between i + 1 and nums.size() - 1
  * Also, as we are supposed to find the unique set, duplicate elements might get duplicate triplets.
  * To avoid this, we skip through the array as it is already sorted for all the 3 pointers - i, j, k.
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int j = 0; j < n; j++) {
            int i = j + 1;
            int k = n - 1;
            
            while (i < k) {
                int curr = nums[i] + nums[k];
                
                if (curr == -nums[j]) {
                    vector<int> triplet = {nums[j], nums[i], nums[k]};
                    ans.push_back(triplet);
                    
                    while (i < k && triplet[1] == nums[i])
                        i++;
                    
                    while (i < k && triplet[2] == nums[k])
                        k--;
                }
                else if (curr > -nums[j])
                    k--;
                else
                    i++;
            }
            
            while (j < n - 1 && nums[j] == nums[j + 1])
                j++;
        }
        
        return ans;
    }
};
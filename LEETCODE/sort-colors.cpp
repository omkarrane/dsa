#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-colors/
/**
 * we can solve this using dutch national flag algorithm
 * here we will place all 0's between 0..low - 1 and 2's between high + 1..n - 1
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[high--], nums[mid]);
        }
    }
};
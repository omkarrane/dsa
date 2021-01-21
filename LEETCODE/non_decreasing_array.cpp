#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-decreasing-array/
class Solution
{
public:
  bool checkPossibility(vector<int> &nums)
  {
    int p = -1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] > nums[i + 1])
      {
        if (p != -1)
          return false;
        p = i;
      }
    }

    if (p == -1)
      return true;
    if (p == nums.size() - 2)
      return true;
    if (p == 0)
      return true;
    return (nums[p - 1] <= nums[p + 1]) || (nums[p] <= nums[p + 2]);
  }
};
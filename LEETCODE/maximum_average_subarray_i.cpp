#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-average-subarray-i/
class Solution
{
public:
  double findMaxAverage(vector<int> &nums, int k)
  {
    int curr = 0, res = 0;
    for (int i = 0; i < k; i++)
      curr += nums[i];

    res = curr;
    for (int i = k; i < nums.size(); i++)
    {
      curr -= nums[i - k];
      curr += nums[i];
      res = max(curr, res);
    }

    return (double)res / k;
  }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/third-maximum-number/
class Solution
{
public:
  int thirdMax(vector<int> &nums)
  {
    vector<int> arr;
    arr.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
      if (arr.size() < 3)
      {
        if (arr.size() == 1 && arr[0] == nums[i])
          continue;
        if (arr.size() == 2 && (arr[0] == nums[i] || arr[1] == nums[i]))
          continue;
        arr.push_back(nums[i]);
        sort(arr.begin(), arr.end(), greater<int>());
        continue;
      }

      if (nums[i] > arr[0])
      {
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = nums[i];
      }
      else if (nums[i] > arr[1] && nums[i] != arr[0])
      {
        arr[2] = arr[1];
        arr[1] = nums[i];
      }
      else if (nums[i] > arr[2] && nums[i] != arr[0] && nums[i] != arr[1])
      {
        arr[2] = nums[i];
      }
    }

    if (arr.size() < 3)
      return arr[0];
    return arr[2];
  }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int max_building = 0;
    for (int i = 0; i < height.size(); i++)
      if (height[max_building] < height[i])
        max_building = i;

    int left_max = 0, water_trapped = 0;
    for (int i = 0; i < max_building; i++)
    {
      if (height[left_max] < height[i])
      {
        left_max = i;
      }
      else
      {
        water_trapped += (height[left_max] - height[i]);
      }
    }

    int right_max = height.size() - 1;
    for (int i = height.size() - 1; i > max_building; i--)
    {
      if (height[right_max] < height[i])
      {
        right_max = i;
      }
      else
      {
        water_trapped += (height[right_max] - height[i]);
      }
    }

    return water_trapped;
  }
};
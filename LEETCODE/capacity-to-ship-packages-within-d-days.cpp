#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution
{
public:
  bool isPossible(vector<int> &weights, int D, int load)
  {
    int days = D, boxes = 0;
    int i = 0;
    long long sum = 0;
    while (i < weights.size())
    {
      if (days == 0)
        break;

      if (sum + weights[i] <= load)
      {
        sum += weights[i];
        boxes++;
        i++;
      }
      else
      {
        days--;
        sum = 0;
      }
    }

    return boxes == weights.size();
  }

  int shipWithinDays(vector<int> &weights, int D)
  {
    int low = 1;
    int high = 500000;
    int ans = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      bool possible1 = isPossible(weights, D, mid);
      if (possible1)
      {
        ans = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
    }

    return ans;
  }
};
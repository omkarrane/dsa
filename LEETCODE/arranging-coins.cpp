#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/arranging-coins/
class Solution
{
public:
  int arrangeCoins(int n)
  {
    long long low = 1;
    long long high = INT_MAX;
    while (low <= high)
    {
      long long mid = low + (high - low) / 2;
      long long sum1 = mid * (mid + 1) / 2;
      long long sum2 = (mid + 1) * (mid + 2) / 2;

      if (sum1 <= n && sum2 > n)
        return mid;
      else if (sum1 <= n)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return 0;
  }
};
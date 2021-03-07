#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/
class Solution
{
public:
  bool isPossible(vector<int> &piles, int H, long long K)
  {
    if (K == 0)
      return false;
    int n = piles.size();
    int current = 0;
    long long hoursTaken = 0;
    while (current < n)
    {
      hoursTaken += (piles[current] / K);
      if (piles[current] % K != 0)
        hoursTaken++;
      current++;
    }

    return hoursTaken <= H;
  }

  int minEatingSpeed(vector<int> &piles, int H)
  {
    int n = piles.size();
    long long low = 1;
    long long high = 1;
    while (!isPossible(piles, H, high))
      high *= 2;

    long long ans = 1;
    while (low <= high)
    {
      long long mid = low + (high - low) / 2;
      bool possible1 = isPossible(piles, H, mid);

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
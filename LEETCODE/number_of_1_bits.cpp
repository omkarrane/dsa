#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/
class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int ans = 0;
    for (int i = 0; i < 32; i++)
      if (n & 1 << i)
        ans++;

    return ans;
  }
};
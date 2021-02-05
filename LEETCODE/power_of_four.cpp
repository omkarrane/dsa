#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/power-of-four/
class Solution
{
public:
  bool isPowerOfFour(int n)
  {
    int i = 0;
    while (i < 32)
    {
      if ((1 << i) == n)
        return true;
      i += 2;
    }

    return false;
  }
};
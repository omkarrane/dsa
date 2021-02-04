#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/power-of-two/
class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    int i = 0;
    while (i < 31)
    {
      if (n == (1 << i))
        return true;
      i++;
    }

    return false;
  }
};
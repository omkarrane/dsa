#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-number-with-alternating-bits/
class Solution
{
public:
  bool hasAlternatingBits(int n)
  {
    int i = 1;
    while (i < 32 && (1 << i) <= n)
    {
      if ((n & (1 << i)) == 0 && (n & (1 << (i - 1))) == 0)
        return false;
      else if ((n & (1 << i)) > 0 && (n & (1 << (i - 1))) > 0)
        return false;
      i++;
    }

    return true;
  }
};
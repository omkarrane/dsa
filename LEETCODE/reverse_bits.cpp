#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-bits/
class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t rev = 0;
    int i = 0;
    while (i < 32)
    {
      if ((n & (1 << i)) > 0)
        rev |= (1 << (31 - i));
      i++;
    }

    return rev;
  }
};
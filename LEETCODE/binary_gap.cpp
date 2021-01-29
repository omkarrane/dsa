#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-gap/
class Solution
{
public:
  int binaryGap(int n)
  {
    int gap = 0, prev = -1, curr = 0;
    while (n != 0)
    {
      if (n & 1 && prev != -1)
      {
        gap = max(gap, curr - prev);
        prev = curr;
      }
      else if (n & 1)
      {
        prev = curr;
      }

      n = n >> 1;
      curr++;
    }

    return gap;
  }
};
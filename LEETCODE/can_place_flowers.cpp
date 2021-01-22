#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/can-place-flowers/
class Solution
{
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n)
  {
    for (int i = 0; i < flowerbed.size(); i++)
    {
      if (flowerbed[i] == 1)
        i++;
      else if (flowerbed[i] == 0)
      {
        bool p = true;
        if (i > 0 && flowerbed[i - 1] == 1)
          p = false;
        if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1)
          p = false;
        if (p)
        {
          i++;
          n--;
        }
      }
    }

    return n <= 0;
  }
};
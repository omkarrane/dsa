#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-mountain-array/
class Solution
{
public:
  bool validMountainArray(vector<int> &arr)
  {
    if (arr.size() < 3)
      return false;

    int i = 0, j = arr.size() - 1;
    while (i < arr.size() && arr[i] < arr[i + 1])
      i++;
    while (j > 0 && arr[j] < arr[j - 1])
      j--;

    if (i == 0 || j == arr.size() - 1)
      return false;
    return i == j;
  }
};
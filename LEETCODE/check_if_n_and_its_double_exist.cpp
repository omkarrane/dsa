#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-n-and-its-double-exist/
class Solution
{
public:
  bool checkIfExist(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    bool zero = false;
    for (int i = 0; i < arr.size(); i++)
    {
      int toFind = arr[i] * 2;
      if (toFind == 0 && zero)
        return true;
      else if (toFind == 0)
      {
        zero = true;
        continue;
      }
      int index = lower_bound(arr.begin(), arr.end(), toFind) - arr.begin();
      if (index >= 0 && index < arr.size() && toFind == arr[index])
        return true;
    }

    return false;
  }
};
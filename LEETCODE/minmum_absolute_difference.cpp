#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-absolute-difference/
class Solution
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    int smallest = INT_MAX, curr = 0;
    for (int i = 1; i < arr.size(); i++)
    {
      curr = arr[i] - arr[i - 1];
      if (curr < smallest)
        smallest = curr;
    }

    vector<vector<int>> res;
    for (int i = 1; i < arr.size(); i++)
    {
      if (arr[i] - arr[i - 1] == smallest)
      {
        res.push_back({arr[i - 1], arr[i]});
      }
    }

    return res;
  }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/queries-on-a-permutation-with-key/
class Solution
{
public:
  vector<int> processQueries(vector<int> &queries, int m)
  {
    vector<int> arr;
    for (int i = 1; i <= m; i++)
      arr.push_back(i);

    vector<int> res;
    for (int j = 0; j < queries.size(); j++)
    {
      int curr = 0;
      while (arr[curr] != queries[j])
        curr++;

      arr.erase(arr.begin() + curr);
      arr.insert(arr.begin(), queries[j]);
      res.push_back(curr);
    }

    return res;
  }
};
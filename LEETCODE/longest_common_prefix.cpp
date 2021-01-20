#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-prefix/
class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.size() == 0)
      return "";

    string ans = "";
    string curr = "";
    string c = strs[0];
    for (int i = 0; i < c.length(); i++)
    {
      bool flag = true;
      for (int j = 1; j < strs.size(); j++)
      {
        if (strs[j][i] != c[i])
          flag = false;
      }
      if (!flag)
        break;

      curr.push_back(c[i]);
      if (curr.length() > ans.length())
        ans = curr;
    }

    return ans;
  }
};
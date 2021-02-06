#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-difference/
class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    int ex = 0;
    for (int i = 0; i < s.size(); i++)
      ex ^= (int)s[i];

    for (int i = 0; i < t.size(); i++)
      ex ^= (int)t[i];

    return (char)ex;
  }
};
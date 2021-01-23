#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
class Solution
{
public:
  bool hasGroupsSizeX(vector<int> &deck)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < deck.size(); i++)
    {
      if (m.find(deck[i]) == m.end())
        m[deck[i]] = 1;
      else
        m[deck[i]]++;
    }

    int gcd = m.begin()->second;
    for (auto i : m)
    {
      gcd = __gcd(gcd, i.second);
    }

    return gcd >= 2;
  }
};
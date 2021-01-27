#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reveal-cards-in-increasing-order/
class Solution
{
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck)
  {
    sort(deck.begin(), deck.end());
    deque<int> indexes;
    for (int i = 0; i < deck.size(); i++)
      indexes.push_back(i);

    vector<int> fi(deck.size());
    int temp;
    for (int i = 0; i < deck.size(); i++)
    {
      temp = indexes.front();
      fi[temp] = deck[i];
      indexes.pop_front();
      indexes.push_back(indexes.front());
      indexes.pop_front();
    }

    return fi;
  }
};
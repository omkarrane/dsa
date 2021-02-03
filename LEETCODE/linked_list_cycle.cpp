#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3627/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
      return false;
    ListNode *slow = head->next;
    ListNode *fast = head->next->next;

    while (fast != slow)
    {
      if (fast->next == NULL || fast->next->next == NULL || slow->next == NULL)
        return false;

      fast = fast->next->next;
      slow = slow->next;
    }

    return true;
  }
};
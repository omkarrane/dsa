#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;

    ListNode *merged;
    if (l1->val <= l2->val)
    {
      merged = new ListNode(l1->val);
      l1 = l1->next;
    }
    else
    {
      merged = new ListNode(l2->val);
      l2 = l2->next;
    }
    ListNode *head = merged;

    while (l1 != NULL && l2 != NULL)
    {
      if (l1->val <= l2->val)
      {
        merged->next = l1;
        l1 = l1->next;
      }
      else
      {
        merged->next = l2;
        l2 = l2->next;
      }
      merged = merged->next;
    }

    while (l1 != NULL)
    {
      merged->next = l1;
      l1 = l1->next;
      merged = merged->next;
    }

    while (l2 != NULL)
    {
      merged->next = l2;
      l2 = l2->next;
      merged = merged->next;
    }

    return head;
  }
};
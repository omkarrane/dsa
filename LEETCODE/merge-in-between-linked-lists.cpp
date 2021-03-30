#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-in-between-linked-lists/
/**
 * we can just iterate through list1 finding the ath and bth node
 * now just point ath node to list2 and the end of list2 to bth node->next
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = list1;
        ListNode* prevFirst = list1;
        
        int i = 0;
        while (first != NULL && i != a) {
            prevFirst = first;
            first = first->next;
            i++;
        }
        
        ListNode* second = first;
        while (second != NULL && i != b) {
            second = second->next;
            i++;
        }
        
        prevFirst->next = list2;
        while (prevFirst->next != NULL) {
            prevFirst = prevFirst->next;   
        }
        
        prevFirst->next = second->next;
        
        return list1;
    }
};
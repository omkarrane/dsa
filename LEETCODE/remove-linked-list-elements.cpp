#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-linked-list-elements/
/**
 * we can just maintain 2 pointers for previous and current node
 * now iterate over the list and delete the link from previous to current if current->val matches val
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current != NULL) {
            if (current->val == val && prev != NULL)
                prev->next = current->next;
            else
                prev = current;
            
            current = current->next;
        }
        
        return head;
    }
};
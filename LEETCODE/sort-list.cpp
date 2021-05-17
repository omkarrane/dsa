#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-list/
/**
  * We use the merge-sort to solve this question.
  * As we are dealing with pointers, we don't need any extra space to partition the list.
  * We can just find the middle node of a list and split it using that node.
  * Once we split the node, we can use the merge function to sort the list.
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
    ListNode* getMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* og = new ListNode(-1);
        ListNode* head3 = og;
        
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                head3->next = head1;
                head1 = head1->next;
            }
            else {
                head3->next = head2;
                head2 = head2->next;
            }
            head3 = head3->next;
        }
        
        if (head1 != NULL)
            head3->next = head1;
        else
            head3->next = head2;
        
        return og->next;
    }
    
    ListNode* partition(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* middle = getMiddle(head);
        ListNode* copy = middle->next;
        middle->next = NULL;
        ListNode* head1 = partition(head);
        ListNode* head2 = partition(copy);
        
        return merge(head1, head2);
    }
    
    ListNode* sortList(ListNode* head) {
        return partition(head);
    }
};
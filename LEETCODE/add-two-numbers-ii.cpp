#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-two-numbers-ii/
/**
 * for this, we reverse both the linked lists and add them handling carry condition
 * once done, we reverse the answer to return
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
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        
        ListNode* l3 = new ListNode(0);
        ListNode* ans = l3;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL) {
            int num = carry;
            
            if (l1 != NULL) {
                num += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                num += l2->val;
                l2 = l2->next;
            }
            
            if (num > 9) {
                carry = num / 10;
                num %= 10;
            }
            else {
                carry = 0;
            }
            
            l3->next = new ListNode(num);
            l3 = l3->next;
        }
        
        if (carry == 1) {
            l3->next = new ListNode(carry);
            l3 = l3->next; 
        }
        
        ans = ans->next;
        l3 = reverseLL(ans);
        return l3;
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        
        int a = l1->val + l2->val;
        int carry = 0;
        
        if (a > 9) {
            a = a % 10;
            carry = 1;
        }
        
        l3 = new ListNode(a);
        ListNode* ans = l3;
        
        l1 = l1->next;
        l2 = l2->next;
        
        int current = 0;
        while (l1 != NULL || l2 != NULL) {
            current = carry;
            
            if (l1 != NULL) {
                current += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                current += l2->val;
                l2 = l2->next;
            }
            
            if (current > 9) {
                carry = 1;
                current %= 10;
            }
            else {
                carry = 0;
            }
            
            l3->next = new ListNode(current);
            l3 = l3->next;
        }
        
        if (carry == 1)
            l3->next = new ListNode(carry);
        
        return ans;
    }
};
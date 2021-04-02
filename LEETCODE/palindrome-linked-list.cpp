#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/
/**
 * For this, we find the mid of the list first and reverse the second half
 * once reversed, we just check if the first and second halves have same values
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
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* second = NULL;
        if (fast == NULL)
            second = reverseLL(slow);
        else
            second = reverseLL(slow->next);
        
        ListNode* first = head;
        while (second != NULL) {
            if (second->val != first->val)
                return false;
            second = second->next;
            first = first->next;
        }
        
        return true;
    }
};
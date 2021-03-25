#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-node-in-linked-list/
/**
 * reverse the linked list
 * now solve this in a similar fashion as next greater element using a stack
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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int n = 0;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n++;
        }
        
        curr = prev;
        stack<int> st;
        vector<int> ans(n, 0);
        int i = 0;
        while (curr != NULL) {
            while (!st.empty()) {
                if (st.top() > curr->val) {
                    ans[i] = st.top();
                    break;
                }
                
                st.pop();
            }
            
            st.push(curr->val);
            curr = curr->next;
            i++;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
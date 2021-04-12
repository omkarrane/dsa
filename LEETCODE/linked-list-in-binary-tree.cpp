#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-in-binary-tree/
/**
 * we can do a recursive search from each node in a tree to see if there is a linked list in downwards direction 
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool combineHelper(TreeNode* root, ListNode* head, ListNode* current) {
        if (current == NULL)
            return true;        
        
        if (root == NULL)
            return false;
        
        if (root->val == current->val)
            return combineHelper(root->left, head, current->next) || combineHelper(root->right, head, current->next);
        
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL)
            return true;
        if (root == NULL)
            return false;
        
        return combineHelper(root, head, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
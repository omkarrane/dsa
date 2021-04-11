#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/symmetric-tree/
/**
 * We can solve this 2 ways: recursive and iterative
 * for recursion, we can check directly for the left and right subtrees, compare them and recurse on both sides in opposite ways
 * for iteration, we can observe that for symmetricity the level should be a palindrome. hence, just do a bfs traversal and check if the current level is palindrome or not 
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
    bool combineHelper(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL)
            return true;
        if (A == NULL || B == NULL)
            return false;
        
        if (A->val != B->val)
            return false;
        
        return combineHelper(A->left, B->right) && combineHelper(A->right, B->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return combineHelper(root->left, root->right);
    }

    bool isPalindrome(vector<TreeNode*> &A) {
        int i = 0;
        int j = A.size() - 1;
        
        while (i < j) {
            if (A[i] == NULL && A[j] == NULL) {
                i++;
                j--;
            }
            else if (A[i] == NULL || A[j] == NULL)
                return false;
            else if (A[i]->val != A[j]->val)
                return false;
            else {
                i++;
                j--;
            }
        }
        
        return true;
    } 
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            
            vector<TreeNode*> temp;
            while (n--) {
                TreeNode* current = q.front();
                q.pop();
                temp.push_back(current);
                
                if (current != NULL)
                    q.push(current->left);
                if (current != NULL)
                    q.push(current->right);
            }
            
            if (!isPalindrome(temp))
                return false;
        }
        
        return true;
    }
};
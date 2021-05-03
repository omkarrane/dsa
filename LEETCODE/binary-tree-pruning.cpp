#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-pruning/
/**
 * a preorder traversal to prune the left and right subtrees and then prune the current node if required
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
    bool prune(TreeNode* root) {
        if (root == NULL)
            return false;
        
        bool l = prune(root->left);
        bool r = prune(root->right);
        
        if (!l) 
            root->left = NULL;
        if (!r)
            root->right = NULL;
        if (!l && !r && root->val == 0) {
            root = NULL;
            return false;            
        }
        
        if (root->val == 1)
            return true;
        
        if (l || r)
            return true;
        
        
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL)
            return root;
        
        bool pruning = prune(root);
        if (pruning)
            return root;
        return NULL;
    }
};
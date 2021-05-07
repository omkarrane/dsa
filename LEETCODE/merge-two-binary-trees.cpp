#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-binary-trees/
/**
 * merge the 2 roots and recursively do the same for every left and right subtree
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;
        
        TreeNode* current = new TreeNode(root1->val + root2->val);
        current->left = mergeTrees(root1->left, root2->left);
        current->right = mergeTrees(root1->right, root2->right);
        
        return current;
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/
/**
 * preorder traversal while maintaining a global variable for max diameter
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
    int diameter = 0;
    
    int combineSolver(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        if (root->left == NULL && root->right == NULL)
            return 1;
        
        int l = combineSolver(root->left);
        int r = combineSolver(root->right);
        
        diameter = max(diameter, l + r + 1);
        
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        int temp = combineSolver(root);
        return max(0, diameter - 1);
    }
};
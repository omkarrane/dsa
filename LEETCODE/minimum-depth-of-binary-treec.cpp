#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-depth-of-binary-tree/
/**
 * a recursive approach to finding the height of left and right subtree and returning the min
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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        if (root->left == NULL && root->right == NULL)
            return 1;
    
        int current = INT_MAX;
        if (root->left != NULL)
            current = min(current, minDepth(root->left) + 1);
        
        if (root->right != NULL)
            current = min(current, minDepth(root->right) + 1);
        
        return current;
    }
};
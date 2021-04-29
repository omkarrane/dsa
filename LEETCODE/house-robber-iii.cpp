#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-iii/
/**
 * this can simply be solved using recursion with memoization for both possibilities
 * 1. include current node and skip children
 * 2. skip current and add children
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
    map<TreeNode*, int> dp;
    
    int combineSolver(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        if (dp.find(root) != dp.end())
            return dp[root];
        
        int with = root->val;
        if (root->left != NULL) {
            with += combineSolver(root->left->left) + combineSolver(root->left->right);
        }
        if (root->right != NULL) {
            with += combineSolver(root->right->left) + combineSolver(root->right->right);
        }
        
        int without = combineSolver(root->left) + combineSolver(root->right);
        
        return dp[root] = max(with, without);
    }
    
    int rob(TreeNode* root) {
        dp = map<TreeNode*, int>();
        return combineSolver(root);
    }
};
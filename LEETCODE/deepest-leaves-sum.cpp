#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/deepest-leaves-sum/
/**
 * we can do a preorder depth first search traversal and calculate the sum directly
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
    int height = 0;
    int sum = 0;
    
    void combineHelper(TreeNode* root, int level) {
        if (root == NULL) 
            return;
        
        if (root->left == NULL && root->right == NULL) {
            if (level == height)
                sum += root->val;
            else if (level > height) {
                height = level;
                sum = root->val;
            }
        }
        
        combineHelper(root->left, level + 1);
        combineHelper(root->right, level + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        combineHelper(root, 1);
        return sum;
    }
};
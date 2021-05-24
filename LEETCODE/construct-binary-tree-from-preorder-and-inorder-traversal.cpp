#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    int preorderindex = 0;
    
    TreeNode* buildTree(vector<int> &preorder, unordered_map<int, int> &m, int i, int j) {
        if (i > j)
            return NULL;
        
        int eleindex = m[preorder[preorderindex]];
        TreeNode* current = new TreeNode(preorder[preorderindex]);
        preorderindex++;
        current->left = buildTree(preorder, m, i, eleindex - 1);
        current->right = buildTree(preorder, m, eleindex + 1, j);
        
        return current;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderindex = 0;
        unordered_map<int, int> m;
        int n = inorder.size();
        
        for (int i = 0; i < n; i++)
            m[inorder[i]] = i;
        
        return buildTree(preorder, m, 0, n - 1);
    }
};
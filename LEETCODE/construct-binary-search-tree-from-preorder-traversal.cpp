#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
/**
 * an inorder traversal of a bst is always sorted, using this fact to generate inorder traversal we can generate the tree
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
    TreeNode* generate(vector<int> &inorder, vector<int> &preorder, map<int, int> &hash, int low, int high, int &preorderindex) {
        if (preorderindex == preorder.size())
            return NULL;
        if (low > high)
            return NULL;
        
        int inorderindex = hash[preorder[preorderindex]];
        preorderindex++;
        TreeNode* current = new TreeNode(inorder[inorderindex]);
        current->left = generate(inorder, preorder, hash, low, inorderindex - 1, preorderindex);
        current->right = generate(inorder, preorder, hash, inorderindex + 1, high, preorderindex);
        
        return current;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        
        int preorderindex = 0;
        TreeNode* root = generate(inorder, preorder, hash, 0, inorder.size() - 1, preorderindex);
        return root;
    }
};
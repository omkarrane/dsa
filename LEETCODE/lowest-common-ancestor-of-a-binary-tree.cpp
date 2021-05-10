#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
	* 	We can solve this recursively for finding the LCA of the 2 nodes.
	* 	First check if any of the nodes is equal to the root. If yes, then return root.
	* 	Now, do a preorder traversal on the left and right sub-trees recursively.
	* 	Then check for the return values of both the recursive calls. If both of them return values, then root node is the LCA. Else return the one which returns a non NULL value.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return root;
        
        if (root == p || root == q)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if (l && r)
            return root;
        else if (l)
            return l;
        return r;
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
1. Approach 1 using Recursion
	* 	We can solve this recursively for finding the LCA of the 2 nodes.
	* 	First check if any of the nodes is equal to the root. If yes, then return root.
	* 	Now, do a preorder traversal on the left and right sub-trees recursively.
	* 	Then check for the return values of both the recursive calls. If both of them return values, then root node is the LCA. Else return the one which returns a non NULL value.

2. Approach 2 using Iterative Stacks
	*  Start from the root node and traverse the tree.
	*  Until we find p and q both, keep storing the parent pointers in a dictionary.
	*  Once we have found both p and q, we get all the ancestors for p using the parent dictionary and add to a set called ancestors.
	*  Similarly, we traverse through ancestors for node q. If the ancestor is present in the ancestors set for p, this means this is the first ancestor common between p and q (while traversing upwards) and hence this is the LCA node.
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


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> st;
        st.push(root);
        parent[root] = NULL;
        
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* current = st.top();
            st.pop();
            
            if (current->left) {
                parent[current->left] = current;
                st.push(current->left);
            }
            
            if (current->right) {
                parent[current->right] = current;
                st.push(current->right);
            }
        }
        
        set<TreeNode*> ancestors;
        while (p != NULL) {
            ancestors.insert(p);
            p = parent[p];
        }
        
        while (ancestors.find(q) == ancestors.end())
            q = parent[q];
        
        return q;
    }
};
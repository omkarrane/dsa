#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
/**
  * We can exploit the property that the inorder traversal of a BST is always sorted.
  * We can do simple iterative or recursive traversal and return the kth element.
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (root != NULL) {
            st.push(root);  
            root = root->left;
        }
        
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            k--;
            
            if (k == 0)
                return curr->val;
            
            curr = curr->right;
            
            if (curr == NULL)
                continue;
            
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
        }
        
        return 0;
    }
};
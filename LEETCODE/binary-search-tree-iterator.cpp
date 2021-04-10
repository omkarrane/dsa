#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-search-tree-iterator/
/**
 * Implement a forward iterator by going to the extreme left while storing all the intermediate nodes
 * the intermediate nodes will be stored in a stack for backtracking
 * for the next() call, we will pop the top most element to return, we will also store all the elements from st.top()->right in the stack
 * for the hasNext() call, we will just check if the stack is empty or not
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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*>();
        forwardIterator(root);
    }
    
    int next() {
        TreeNode* A = st.top();
        st.pop();
        forwardIterator(A->right);
        return A->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void forwardIterator(TreeNode* A) {
        if (A == NULL)
            return;
        
        st.push(A);
        forwardIterator(A->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/**
  * We can do a simple level order traversal to iterator through the tree.
  * On every level, we see if its a odd level or even level.
  * On every odd level we just reverse the elements in the temp array, and then push to the result array.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> current;
            level ^= 1;
            
            while (n--) {
                TreeNode* a = q.front();
                q.pop();
                
                if (a == NULL)
                    continue;
                
                q.push(a->left);
                q.push(a->right);
                current.push_back(a->val);
            }
            
            if (level == 0)
                reverse(current.begin(), current.end());
            
            if (!current.empty())
                ans.push_back(current);
        }
        
        return ans;
    }
};
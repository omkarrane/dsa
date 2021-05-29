#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/
/**
  * We could just maintain the final answer array and check if current level is equal to size of the array.
  * If yes, then we add one more element to the array.
  * Now we do a pre-order traversal and go to the left side first and update the variable to its particular level, then go to the right side.
  * Also, we can solve this using BFS as well.
  * We put all the nodes in the queue for a particular level and just pick the queue.back() as the visible node for the level.
  * We then, push all the left and right nodes for the next level until the whole tree is iterated.
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
    vector<int> ans;
    
    void combineSolver(TreeNode* root, int level) {
        if (root == NULL)
            return;
        
        if (ans.size() == level)
            ans.push_back(0);
        
        ans[level] = root->val;
        combineSolver(root->left, level + 1);
        combineSolver(root->right, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        ans = vector<int>();
        combineSolver(root, 0);
        return ans;
    }
};
// https://leetcode.com/problems/diameter-of-binary-tree

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
    /* height, diameter */
    pair<int, int> helper(TreeNode *root)
    {
        if(root == NULL)
            return {0, 0};
        
        pair<int, int> l = helper(root->left);
        pair<int, int> r = helper(root->right);
        
        return {max(l.first, r.first) + 1, max({l.second, r.second, l.first + r.first})};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};
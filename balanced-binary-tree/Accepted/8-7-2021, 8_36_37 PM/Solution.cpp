// https://leetcode.com/problems/balanced-binary-tree

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
    pair<int, bool> helper(TreeNode *root)
    {
        if(root == NULL)
            return {0, true};
        
        pair<int, bool> l = helper(root->left);
        pair<int, bool> r = helper(root->right);
        int h = max(l.first, r.first) + 1;
        
        bool output = l.second && r.second && (abs(r.first - l.first) <= 1);
        return {h, output};
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root).second;
    }
};
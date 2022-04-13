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
    bool helper(TreeNode *root, int &h)
    {
        if(root == NULL)
            return true;
        
        int lh = 0, rh = 0;
        if(!helper(root->left, lh) || !helper(root->right, rh))
            return false;
        h = max(lh, rh) + 1;
        
        return (abs(lh - rh) <= 1);
    }
    
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return helper(root, h);
    }
};
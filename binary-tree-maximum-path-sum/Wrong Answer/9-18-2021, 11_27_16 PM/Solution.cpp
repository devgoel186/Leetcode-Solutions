// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int helper(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int a = maxPathSum(root->left);
        int b = maxPathSum(root->right);
        return max({a, b, a + b + root->val, 0});
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int x = helper(root->right); 
        int y = helper(root->left);
        return max({x, y, x + y + root->val, 0});
    }
};
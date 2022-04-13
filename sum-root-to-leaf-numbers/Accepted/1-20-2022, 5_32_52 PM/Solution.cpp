// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void helper(TreeNode *root, int sum, int &total)
    {
        if(!root->left && !root->right)
        {
            total += sum;
            return;
        }
        
        if(root->left)
            helper(root->left, sum * 10 + root->left->val, total);
        
        if(root->right)
            helper(root->right, sum * 10 + root->right->val, total);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int total = 0;
        helper(root, root->val, total);
        
        return total;
    }
};
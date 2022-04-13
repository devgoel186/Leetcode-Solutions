// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    int helper(TreeNode *root, int sum, int &mx)
    {
        if(root == NULL)
            return 0;
        
        int a = helper(root->left, sum, mx);
        int b = helper(root->right, sum, mx);
        
        int lb = a * (sum - a);
        int rb = b * (sum - b);
        
        mx = max({lb, rb, mx});
        
        return a + root->val + b;
    }
    
    int totalSum(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        return totalSum(root->left) + totalSum(root->right) + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        int mx = INT_MIN;
        int sum = totalSum(root);
        helper(root, sum, mx);
        return mx;
    }
};
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
    const int MOD = 1e9 + 7;
    
    long long helper(TreeNode *root, long long sum, long long &mx)
    {
        if(root == NULL)
            return 0;
        
        long long a = helper(root->left, sum, mx);
        long long b = helper(root->right, sum, mx);
        
        long long lb = (a) * (sum - a);
        long long rb = (b) * (sum - b);
        
        mx = max({lb, rb, mx});
        
        return (a + root->val + b);
    }
    
    long long totalSum(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        return (totalSum(root->left) + totalSum(root->right) + root->val);
    }
    
    int maxProduct(TreeNode* root) {
        long long mx = 0;
        long long sum = totalSum(root);
        helper(root, sum, mx);
        return mx % MOD;
    }
};
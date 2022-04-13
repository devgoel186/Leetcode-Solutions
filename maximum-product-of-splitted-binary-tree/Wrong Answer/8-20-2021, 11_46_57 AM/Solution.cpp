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
    int helper(TreeNode *root, int &mx)
    {
        if(root == NULL)
            return 0;
        
        int a = helper(root->left, mx);
        int b = helper(root->right, mx);
        
        mx = max({mx, ((a + root->val) * b), (a * (b + root->val))});
        
        return a + root->val + b;
    }
    
    int maxProduct(TreeNode* root) {
        int mx = INT_MIN;
        helper(root, mx);
        return mx;
    }
};
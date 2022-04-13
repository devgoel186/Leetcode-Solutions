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
    int maxSum = INT_MIN;
    
    int helper(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int a = max(helper(root->left), 0);
        int b = max(helper(root->right), 0);
        maxSum = max(maxSum, a + b + root->val);
        return max(a, b) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        helper(root);
        return maxSum;
    }
};
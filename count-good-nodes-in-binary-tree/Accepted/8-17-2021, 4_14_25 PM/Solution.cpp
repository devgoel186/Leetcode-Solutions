// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int helper(TreeNode *root, int maxVal)
    {
        if(root == NULL)
            return 0;
        
        int add = 0;
        if(root->val >= maxVal)
            add++;
        
        maxVal = max(maxVal, root->val);
        
        return helper(root->left, maxVal) + helper(root->right, maxVal) + add;
    }
    
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
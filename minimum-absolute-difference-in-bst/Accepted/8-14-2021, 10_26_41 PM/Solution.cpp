// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    pair<int, int> helper(TreeNode *root, int &diff)
    {
        if(root == NULL)
            return {1e6, -1 * 1e6};
        
        /* diff, min, max */
        pair<int, int> l = helper(root->left, diff);
        pair<int, int> r = helper(root->right, diff);
        
        diff = min(diff, root->val - l.second);
        diff = min(diff, r.first - root->val);
        
        return {min(root->val, l.first), max(root->val, r.second)};
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int diff = 1e6;
        helper(root, diff);        
        return diff;
    }
};
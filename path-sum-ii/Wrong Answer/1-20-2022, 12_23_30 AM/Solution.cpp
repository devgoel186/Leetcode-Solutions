// https://leetcode.com/problems/path-sum-ii

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
    void helper(TreeNode *root, vector<vector<int>> &res, vector<int> &ans, int sum, int target)
    {
        if(sum == target && !root->left && !root->right)
        {
            res.push_back(ans);
            return;
        }
        
        if(root->left && root->left->val + sum <= target)
        {
            ans.push_back(root->left->val);
            helper(root->left, res, ans, sum + root->left->val, target);
            ans.pop_back();
        }
        
        if(root->right && root->right->val + sum <= target)
        {
            ans.push_back(root->right->val);
            helper(root->right, res, ans, sum + root->right->val, target);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        vector<int> ans;
        ans.push_back(root->val);
        helper(root, res, ans, root->val, targetSum);
        
        return res;
    }
};
// https://leetcode.com/problems/binary-tree-paths

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
    void helper(vector<string> &res, string ans, TreeNode *root)
    {
        if(!root->left && !root->right)
        {
            ans += to_string(root->val);
            res.push_back(ans);
            return;
        }
        
        if(root->left)
            helper(res, ans + to_string(root->val) + "->", root->left);
        
        if(root->right)
            helper(res, ans + to_string(root->val) + "->", root->right);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)   
            return {};
        
        vector<string> res;
        helper(res, "", root);
        
        return res;
    }
};
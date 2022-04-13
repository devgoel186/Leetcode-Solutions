// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val == targetSum)
                return true;
            return false;
        }
        
        bool cond1 = hasPathSum(root->left, targetSum - root->val);
        bool cond2 = hasPathSum(root->right, targetSum - root->val);
        if(cond1 || cond2)
            return true;
        return false;
    }
};
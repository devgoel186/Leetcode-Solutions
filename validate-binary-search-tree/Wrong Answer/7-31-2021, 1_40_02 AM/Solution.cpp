// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBSTHelper(TreeNode* root, int max, int min) {
        if(root == NULL)
            return true;
        
        bool cond = (root->val < max) && (root->val > min);
        bool l = isValidBSTHelper(root->left, root->val - 1, min);
        bool r = isValidBSTHelper(root->right, max, root->val + 1);
        
        return (cond && l && r);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MAX, INT_MIN);
    }
};
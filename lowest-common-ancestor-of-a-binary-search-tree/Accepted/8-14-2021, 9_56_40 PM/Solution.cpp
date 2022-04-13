// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        
        if(l != NULL && r != NULL)
            return root;
        
        else if(l != NULL)
            return lowestCommonAncestor(root->left, p, q);
        
        else if(r != NULL)
            return lowestCommonAncestor(root->right, p, q);
        
        return NULL;
    }
};
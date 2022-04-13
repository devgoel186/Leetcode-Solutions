// https://leetcode.com/problems/recover-binary-search-tree

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
    TreeNode *a = NULL, *b = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    
    void inorder(TreeNode *root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);
        
        if(a == NULL && prev->val > root->val)
            a = prev;
        
        if(a != NULL && prev->val > root->val)
            b = root;
        
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(a->val, b->val);
    }
};
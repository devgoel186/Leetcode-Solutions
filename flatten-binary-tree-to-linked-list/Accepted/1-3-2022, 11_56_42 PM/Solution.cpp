// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        if(root->right)
            flatten(root->right);
        
        if(root->left)
            flatten(root->left);
        
        if(root->left == NULL)
            return;
        
        TreeNode *temp = root->left;
        while(temp->right != NULL)
            temp = temp->right;
        
        temp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
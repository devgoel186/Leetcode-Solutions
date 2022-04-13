// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetricHelper(TreeNode* root, TreeNode *root2) {
        if(root == NULL && root2 == NULL)
            return true;
        else if(root == NULL || root2 == NULL)
            return false;
        
        bool cond = isSymmetricHelper(root->left, root2->right) && isSymmetricHelper(root->right, root2->left);
        return cond;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return isSymmetricHelper(root->left, root->right);
    }
};
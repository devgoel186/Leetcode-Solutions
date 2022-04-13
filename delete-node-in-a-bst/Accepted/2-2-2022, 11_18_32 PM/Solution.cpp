// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* findNode(TreeNode *root)
    {
        TreeNode *temp = root;
        while(temp->left != NULL)
            temp = temp->left;
        
        return temp;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        
        if(key == root->val)
        {
            if(!root->left && !root->right)
                return NULL;

            if(!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            if(!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            else
            {
                TreeNode *temp = findNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            }
        }
        
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        
        else
            root->right = deleteNode(root->right, key);
        
        return root;
    }
};
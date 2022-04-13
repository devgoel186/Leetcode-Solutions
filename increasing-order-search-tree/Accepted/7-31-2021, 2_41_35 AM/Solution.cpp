// https://leetcode.com/problems/increasing-order-search-tree

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
    void inorderBuild(TreeNode *root, vector<int> &inorder)
    {
        if(root == NULL)    
            return;
        
        inorderBuild(root->left, inorder);
        inorder.push_back(root->val);
        inorderBuild(root->right, inorder);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        inorderBuild(root, inorder);
        
        TreeNode *head = NULL;
        TreeNode *temp = NULL;
        
        for(auto i : inorder)
        {
            if(temp == NULL)
            {
                temp = new TreeNode(i);
                head = temp;
            }
            
            else
            {
                temp->right = new TreeNode(i);
                temp = temp->right;
            }
        }
        
        return head;
    }
};
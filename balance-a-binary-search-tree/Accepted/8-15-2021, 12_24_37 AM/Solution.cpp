// https://leetcode.com/problems/balance-a-binary-search-tree

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
    void inorder(TreeNode *root, vector<int> &res)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
    TreeNode *helper(const vector<int> &ans, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int mid = (l + r) / 2;        
        TreeNode *root = new TreeNode(ans[mid]);
        
        root->left = helper(ans, l, mid - 1);        
        root->right = helper(ans, mid + 1, r);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) 
    {        
        vector<int> ans;
        inorder(root, ans);
        
        TreeNode *rootNew = helper(ans, 0, ans.size() - 1);
        return rootNew;
    }
};
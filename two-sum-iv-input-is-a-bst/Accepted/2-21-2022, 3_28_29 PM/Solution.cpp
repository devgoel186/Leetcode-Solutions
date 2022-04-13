// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    bool traverse(TreeNode *root, unordered_set<int> &m, int k)
    {
        if(root == NULL)
            return false;
        
        if(m.count(k - root->val)) 
            return true;
        
        m.insert(root->val);
        
        return traverse(root->left, m, k) || traverse(root->right, m, k);
    }
    
    public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        
        return traverse(root, m, k);
    }
};
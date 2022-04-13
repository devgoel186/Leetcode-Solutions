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
    void traverse(TreeNode *root, unordered_map<int, int> &m)
    {
        if(root == NULL)
            return;
        
        traverse(root->left, m);
        m[root->val] = 1;
        traverse(root->right, m);
    }
    
    public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> m;
        
        traverse(root, m);
        for(int i = 0; i <= k; i++)
        {
            if((m.find(i) != m.end()) && (m.find(k - i) != m.end()))
                return true;
        }
        
        return false;
    }
};
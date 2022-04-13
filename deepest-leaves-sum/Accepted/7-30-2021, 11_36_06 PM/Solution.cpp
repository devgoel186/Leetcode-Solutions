// https://leetcode.com/problems/deepest-leaves-sum

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
    /* sum, height */
    pair<int, int> deepestLeavesHelper(TreeNode *root)
    {
        if(root == NULL)
            return {0, 0};
        if(root->left == NULL && root->right == NULL)
        {
            return {root->val, 1};
        }
        
        pair<int, int> l = deepestLeavesHelper(root->left);
        pair<int, int> r = deepestLeavesHelper(root->right);
        
        int deepSum;
        
        if(l.second > r.second)
            deepSum = l.first;
        else if(l.second < r.second)
            deepSum = r.first;
        else
            deepSum = l.first + r.first;
        
        return {deepSum, max(l.second, r.second) + 1};
    }
    
    int deepestLeavesSum(TreeNode* root)
    {
        return deepestLeavesHelper(root).first;
    }
};
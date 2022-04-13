// https://leetcode.com/problems/binary-tree-tilt

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
    pair<int, int> helper(TreeNode *root, int &sum)
    {
        if(root == NULL)
            return {0, 0};
        
        pair<int, int> l = helper(root->left, sum);
        pair<int, int> r = helper(root->right, sum);
        
        pair<int, int> ans = make_pair(l.first + r.first + root->val, abs(l.first - r.first));
        sum += ans.second;
        
        return ans;
    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        
        return sum;
    }
};
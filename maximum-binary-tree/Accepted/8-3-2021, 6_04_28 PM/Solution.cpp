// https://leetcode.com/problems/maximum-binary-tree

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
    TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int l, int r) {
        if(l > r)
            return NULL;
        
        int maxIndex = l, max = INT_MIN;
        for(int i = l; i <= r; i++)
        {
            if(nums[i] > max)
            {
                max = nums[i];
                maxIndex = i;
            }
        }
        
        TreeNode *root = new TreeNode(max);
        root->left = constructMaximumBinaryTreeHelper(nums, l, maxIndex - 1);
        root->right = constructMaximumBinaryTreeHelper(nums, maxIndex + 1, r);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);
        return root;
    }
};
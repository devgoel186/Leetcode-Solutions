// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopyHelper(TreeNode* cloned, int target) {
        TreeNode *ans = NULL;
        if(cloned == NULL)
            return NULL;
        
        ans = getTargetCopyHelper(cloned->left, target);
        if(ans != NULL)
            return ans;
        
        if(cloned->val == target)
            return cloned;
        
        ans = getTargetCopyHelper(cloned->right, target);
        return ans;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return getTargetCopyHelper(cloned, target->val);
    }
};
// https://leetcode.com/problems/count-complete-tree-nodes

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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int hl = 0, hr = 0;
        TreeNode *ltemp = root, *rtemp = root;
        
        while(ltemp)
        {
            hl++;
            ltemp = ltemp->left;
        }
        
        while(rtemp)
        {
            hr++;
            rtemp = rtemp->right;
        }
        
        if(hl == hr)
            return pow(2, hl) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
//     int util(TreeNode *root, int index, int local, int &sum)
//     {
//         if(root == NULL)
//             return 0;
        
//         if(root->left == NULL && root->right == NULL)
//             return util(root->left, index + 1) + util(root->right, index + 1) + root->data * pow(2, index);
        
//         int x = util(root->left, index + 1, (local + root->data * pow(2, index)), sum);
//         int y = util(root->right, index + 1, (local + root->data * pow(2, index)), sum);
        
//         return x + y;
//     }
    
    int util(TreeNode *root, int x)
    {
        if(root == NULL)
            return 0;
        
        x = 2 * x + root->val;
        
        if(root->right == NULL && root->left == NULL)
            return x;
        
        return util(root->left, x) + util(root->right, x);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return util(root, 0);
    }
};
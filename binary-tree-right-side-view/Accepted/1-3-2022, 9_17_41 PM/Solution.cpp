// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* x = q.front();
                q.pop();
                
                if(size == 0)
                    res.push_back(x->val);
                
                if(x->left)
                    q.push(x->left);
                
                if(x->right)
                    q.push(x->right);
            }
        }
        
        return res;
    }
};
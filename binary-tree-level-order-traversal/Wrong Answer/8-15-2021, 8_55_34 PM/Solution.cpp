// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push(root);        
        ans.push_back({root->val});
        
        while(!q.empty())
        {
            TreeNode *x = q.front();
            int size = q.size();            
            q.pop();
            
            vector<int> res;
            while(size--)
            {                
                if(x->left != NULL)
                {
                    q.push(x->left);
                    res.push_back(x->left->val);
                }
                
                if(x->right != NULL)
                {
                    q.push(x->right);
                    res.push_back(x->right->val);
                }   
            }
            
            if(res.size() == 0)
                continue;
            ans.push_back(res);
        }
        
        return ans;
    }
};
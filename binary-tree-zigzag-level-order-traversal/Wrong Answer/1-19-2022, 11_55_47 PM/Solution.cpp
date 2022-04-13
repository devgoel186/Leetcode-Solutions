// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode *> q;
        q.push(root);
        bool ltr = false;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans;
            
            while(size--)
            {
                TreeNode* x = q.front();
                q.pop();
                ans.push_back(x->val);
                
                if(ltr)
                {
                    if(x->left)
                        q.push(x->left);
                    if(x->right)
                        q.push(x->right);
                }
                
                else
                {
                    if(x->right)
                        q.push(x->right);
                    if(x->left)
                        q.push(x->left);
                }
            }
            
            ltr = !ltr;
            res.push_back(ans);
        }
        
        // for(int i = 0; i < res.size() / 2; i++)
        //     swap(res[i], res[res.size() - 1 - i]);
        
        return res;
    }
};
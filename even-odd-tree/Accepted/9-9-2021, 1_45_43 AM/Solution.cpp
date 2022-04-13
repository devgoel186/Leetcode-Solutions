// https://leetcode.com/problems/even-odd-tree

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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)
            return true;
        
        queue<TreeNode *> q;
        q.push(root);
        
        int level = 0;
        bool flag = true;
        
        while(!q.empty())
        {
            int size = q.size();
            int prev = flag ? -1 : 1e6;
            
            while(size--)
            {
                TreeNode *x = q.front();
                q.pop();

                if(flag)
                {
                    if((x->val > prev) && (x->val % 2 == 1))
                        prev = x->val;
                    else
                        return false;
                }
                
                else
                {
                    if((x->val < prev) && (x->val % 2 == 0))
                        prev = x->val;
                    else
                        return false;
                }
                
                if(x->left != NULL)
                    q.push(x->left);
                
                if(x->right != NULL)
                    q.push(x->right);
            }
            
            level++;
            flag = !flag;
        }
        
        return true;
    }
};
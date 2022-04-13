// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        
        while(!q.empty())
        {
            multiset<pair<int, int>> s;
            int size = q.size();
            while(size--)
            {
                auto x = q.front();
                q.pop();
                s.insert({x.first, x.second->val});
                
                if(x.second->left)
                    q.push({x.first - 1, x.second->left});
                if(x.second->right)
                    q.push({x.first + 1, x.second->right});
            }
            
            for(auto i : s)
            {
                m[i.first].push_back(i.second);
            }
        }
        
        vector<vector<int>> res;
        
        for(auto i : m)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};
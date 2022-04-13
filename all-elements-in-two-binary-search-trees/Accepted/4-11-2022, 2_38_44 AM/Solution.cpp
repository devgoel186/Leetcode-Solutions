// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    void traverse(priority_queue<int, vector<int>, greater<int>> &pq, TreeNode *root)
    {
        if(root == NULL)
            return;
        
        pq.push(root->val);
        traverse(pq, root->left);
        traverse(pq, root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        traverse(pq, root1);
        traverse(pq, root2);
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
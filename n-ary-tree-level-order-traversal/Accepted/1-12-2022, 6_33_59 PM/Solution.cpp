// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        
        queue<Node *> q;
        q.push(root);        
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while(size--)
            {
                Node *x = q.front();
                q.pop();
                level.push_back(x->val);
                
                for(auto i : x->children)
                    q.push(i);
            }
            
            res.push_back(level);
        }
        
        return res;
    }
};
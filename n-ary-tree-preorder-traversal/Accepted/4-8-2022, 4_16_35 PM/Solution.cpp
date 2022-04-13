// https://leetcode.com/problems/n-ary-tree-preorder-traversal

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
    vector<int> preorder(Node* root) {
        if(root == NULL)
            return {};
        
        vector<int> res;
        
        res.push_back(root->val);
        
        for(int i = 0; i < root->children.size(); i++)
        {
            vector<int> temp = preorder(root->children[i]);
            for(auto j : temp)
                res.push_back(j);
        }

        return res;
    }
};
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<Node *> ans;
            
            while(size--)
            {
                Node *x = q.front();
                q.pop();
                ans.push_back(x);
                
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            
            int i;
            for(i = 1; i < ans.size(); i++)
                ans[i - 1]->next = ans[i];
            
            ans[i - 1]->next = NULL;
        }
        
        return root;
    }
};
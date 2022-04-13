// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node == NULL)
            return NULL;
        
        unordered_map<int, Node *> visited;
        Node *res = makeClone(node, visited);
        return res;
    }
    
    Node* makeClone(Node *node, unordered_map<int, Node *> &visited)
    {
        Node *newNode = new Node(node->val);
        visited[node->val] = newNode;
        
        for(auto i : node->neighbors)
        {
            if(visited.find(i->val) == visited.end())
            {
                Node *next = makeClone(i, visited);
                newNode->neighbors.push_back(next);
            }
            else
                newNode->neighbors.push_back(visited[i->val]);
        }
        return newNode;
    }
};
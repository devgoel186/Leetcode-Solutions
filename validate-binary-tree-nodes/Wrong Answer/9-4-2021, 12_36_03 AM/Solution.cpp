// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    bool dfs(int u, vector<int> &leftChild, vector<int> &rightChild, vector<bool> &visited)
    {
        if(visited[u])
            return false;
        
        visited[u] = true;
        
        if(leftChild[u] != -1  && !dfs(leftChild[u], leftChild, rightChild, visited))
            return false;
        
        if(rightChild[u] != -1 && !dfs(rightChild[u], leftChild, rightChild, visited))
            return false;
        
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        
        for(auto i : leftChild)
            if(i != -1)
                indegree[i]++;
        
        for(auto i : rightChild)
            if(i != -1)
                indegree[i]++;
        
        int root = -1, rootCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                root = i;
                rootCount++;
            }
        }
        
        if(root == -1 || rootCount > 1)
            return false;
        
        vector<bool> visited(n, 0);
        
        bool cond = dfs(root, leftChild, rightChild, visited);
        
        // for(auto i : visited)
        //     if(!i)
        //         return false;
        
        return cond;
    }
};
// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool topoSort(vector<vector<int>> adjl)
    {
        vector<int> indegree(adjl.size(), 0);

        for (int i = 0; i < adjl.size(); i++)
        {
            for (int j = 0; j < adjl[i].size(); j++)
            {
                indegree[adjl[i][j]]++;
            }
        }

        queue<int> q;
        int count = 0;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            count++;

            for (auto i : adjl[top])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        if(count == adjl.size())
            return true;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjl(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjl[u].push_back(v);
        }
        
        return topoSort(adjl);
    }
};
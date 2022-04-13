// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        vector<vector<int>> adjl(numCourses);
        for(int i = 0; i < e; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjl[v].push_back(u);
        }
        
        vector<int> indegree(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++)
        {
            for(int j = 0; j < adjl[i].size(); j++)
            {
                indegree[adjl[i][j]]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {                
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();            
            
            for(auto i : adjl[x])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};
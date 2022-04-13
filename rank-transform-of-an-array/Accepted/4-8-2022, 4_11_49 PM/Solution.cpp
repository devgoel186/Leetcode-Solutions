// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < arr.size(); i++)
            pq.push({arr[i], i});
        
        vector<int> res(pq.size(), 0);
        
        int prev = INT_MIN;
        int rank = 0;
        
        while(!pq.empty())
        {
            pair<int, int> x = pq.top();
            pq.pop();
            
            if(x.first != prev)
                rank++;
            
            res[x.second] = rank;
            prev = x.first;
        }
        
        return res;
    }
};
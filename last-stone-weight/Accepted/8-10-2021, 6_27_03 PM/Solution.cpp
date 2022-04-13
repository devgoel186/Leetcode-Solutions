// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        
        for(int i = 0; i < stones.size(); i++)
            pq.push(stones[i]);
        
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            
            if(pq.empty())
                return x;
            
            int y = pq.top();
            pq.pop();

            if(abs(x - y) != 0)
                pq.push(abs(x - y));
        }
        
        if(pq.empty())
            return 0;
        return pq.top();
    }
};
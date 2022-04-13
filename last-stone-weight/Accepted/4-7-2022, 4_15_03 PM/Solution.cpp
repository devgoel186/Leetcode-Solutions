// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // if(stones.size() )
        
        priority_queue<int, vector<int>> pq;
        
        for(auto i : stones)
            pq.push(i);
        
        while(!pq.empty())
        {
            if(pq.size() <= 1)
                break;
            
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            pq.push(abs(x - y));
        }
        
        return pq.top();
    }
};
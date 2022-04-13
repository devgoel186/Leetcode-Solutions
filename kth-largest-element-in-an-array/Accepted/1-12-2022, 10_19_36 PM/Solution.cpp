// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(auto i : nums)
            pq.push(i);
        
        if(k > pq.size())
            return -1;
        
        k--;
        while(k--)
            pq.pop();
        
        return pq.top();
    }
};
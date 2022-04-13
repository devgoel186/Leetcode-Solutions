// https://leetcode.com/problems/h-index-ii

class Solution {
public:
    int helper(vector<int> &citations, int l, int r)
    {
        if(l > r)
            return -1;
        
        int mid = (l + r) / 2;
        
        if(citations[mid] == mid + 1)
            return mid + 1;
        else if(citations[mid] > mid)
            return max(mid + 1, helper(citations, mid + 1, r));
        return max(mid + 1, helper(citations, l, mid - 1));
    }
    
    int hIndex(vector<int>& citations) {
        return helper(citations, 0, citations.size() - 1);
    }
};
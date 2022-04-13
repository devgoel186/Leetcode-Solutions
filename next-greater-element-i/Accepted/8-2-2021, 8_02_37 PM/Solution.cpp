// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> nge;
        vector<int> res(nums2.size(), 0);
        vector<int> ans;
        
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            if(!s.empty())
            {
                while(!s.empty() && nums2[i] >= s.top())
                {
                    s.pop();
                }
            }
            if(s.empty())
                res[i] = -1;
            else
                res[i] = s.top();
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < nums2.size(); i++)
        {
            nge.insert({nums2[i], res[i]});
        }
        
        // for(auto i : nge)
        //     cout << i.first << " " << i.second;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            int x = nge[nums1[i]];
            ans.push_back(x);
        }
        
        return ans;
    }
};
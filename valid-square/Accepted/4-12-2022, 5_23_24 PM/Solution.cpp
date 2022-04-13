// https://leetcode.com/problems/valid-square

class Solution {
public:
    double calculateDistance(vector<int> &p1, vector<int> &p2)
    {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> arr({p1, p2, p3, p4});
        unordered_set<double> s;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)   
            {
                double dist = calculateDistance(arr[i], arr[j]);
                
                if(dist == 0)
                    return false;
                
                s.insert(dist);
            }
        }
        
        return s.size() == 2;
    }
};
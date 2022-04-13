// https://leetcode.com/problems/invalid-transactions

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, pair<string, int>> m;
        unordered_set<string> res;
        
        for(auto i : transactions)
        {
            vector<string> values;
            stringstream ss(i);

            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                values.push_back(substr);
            }
            
            if(stoi(values[2]) > 1000)
                res.insert(i);
            
            else if(m.find(values[0]) != m.end())
            {
                if(stoi(values[1]) -  m[values[0]].second <= 60)
                {
                    res.insert(m[values[0]].first);
                    res.insert(i);
                }
            } 
            
            else
            {
                m[values[0]] = make_pair(i, stoi(values[1]));
            }
        }
        
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};
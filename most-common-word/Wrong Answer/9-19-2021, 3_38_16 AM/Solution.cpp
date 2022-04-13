// https://leetcode.com/problems/most-common-word

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> s;
        
        for(auto i : banned)
            s.insert(i);
        
        string word = "";
        for(auto i : paragraph)
        {
            if(i == ' ' || i == ',' || i == '.')
            {
                if(s.find(word) == s.end())
                    m[word]++;
                word = "";
            }
            else
                word += tolower(i);
        }
        
        string maxWord = "";
        int maxFreq = 0;
        for(auto i : m)
        {
            if(i.second > maxFreq)
            {
                maxFreq = i.second;
                maxWord = i.first;
            }
        }
        
        return maxWord;
    }
};
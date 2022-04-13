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
            if(i < 65 || (i > 80 && i < 97) || i > 122)
            {
                if(s.find(word) == s.end())
                    m[word]++;
                word = "";
            }
            else
                word += tolower(i);
        }
        
        if(word != "")
            m[word]++;
        
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
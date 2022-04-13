// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> store;
        
        int i = 0;
        string word = "";
        while(i < s.length())
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            
            word += s[i];
            
            if(s[i + 1] == ' ' || (i == s.length() - 1))
            {
                store.push_back(word);
                word = "";
            }
            
            i++;
        }   
        
        for(int i = store.size() - 1; i >= 0; i--)
        {
            word += store[i] + ' ';
        }
        
        return word.substr(0, word.size() - 1);
    }
};
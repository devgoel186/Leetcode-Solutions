// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        unordered_set<string> s;
        bool flag = false;
        
        for(auto i : wordList)
        {
            if(i == endWord)
                flag = true;
            if(i == beginWord)
                continue;
            s.insert(i);
        }
        
        if(!flag)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int trans = 0;
        
        while(!q.empty())
        {
            trans++;
            int size = q.size();
            
            while(size--)
            {
                string curr = q.front();
                q.pop();
                
                for(int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;
                    
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        temp[i] = j;
                        
                        if(temp == curr)
                            continue;                        
                        
                        if(temp == endWord)
                            return trans + 1;
                        
                        if(s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
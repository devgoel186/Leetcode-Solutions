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
                        if(curr[i] == j)
                            continue;
                                                
                        curr[i] = j;
                        
                        if(curr == endWord)
                            return trans + 1;
                        
                        if(s.find(curr) != s.end())
                        {
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    
                    curr = temp;
                }
            }
        }
        
        return trans;
    }
};
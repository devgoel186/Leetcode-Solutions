// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l = searchWord.length();
        int count = 0;
        for(int i = 0; i < sentence.length(); i++)
        {
            if(i == 0 || (sentence[i] == ' '))
            {
                if(sentence.substr(i + 1, l) == searchWord)
                {
                    count++;
                    return count;
                }
            }
        }
        
        return -1;
    }
};
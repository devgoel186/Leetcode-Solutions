// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0;
        for(int i = 0; i < sentence.length(); i++)
        {
            if(i == 0 || (sentence[i - 1] == ' '))
            {
                count++;
                if(sentence.substr(i, searchWord.length()) == searchWord)
                    return count;
            }
        }
        
        return -1;
    }
};
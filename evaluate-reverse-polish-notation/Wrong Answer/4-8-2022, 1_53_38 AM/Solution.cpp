// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            cout << tokens[i] << endl;
            
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-")
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                
                if(tokens[i] == "+")
                    s.push(x + y);
                else if(tokens[i] == "+")
                    s.push(x * y);
                else if(tokens[i] == "-")
                    s.push(y - x);
                else
                    s.push(y / x);
            }
            
            else
            {
                int ch = stoi(tokens[i]);                                
                
                if(ch <= 200 && ch >= -200)
                    s.push(ch);
            }
        }
        
        return s.top();
    }
};
// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x1) {
        if( x1<0){
            return false;
        }
        int x = x1;
        int y = 0;
        while (x!=0){
            int temp= x%10;
            x= x/10;
            y=temp+ y*10;
        }
        if(x1==y){
            return true;
        }
        
        return false;
    }
};
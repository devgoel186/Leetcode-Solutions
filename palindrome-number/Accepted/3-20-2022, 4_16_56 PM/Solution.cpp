// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x1) {
        if( x1<0){
            return false;
        }
        long long x = x1;
        long long y = 0;
        while (x!=0){
            long long temp= x%10;
            x= x/10;
            y=temp+ y*10;
        }
        if(x1==y){
            return true;
        }
        
        return false;
    }
};
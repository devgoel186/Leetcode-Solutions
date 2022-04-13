// https://leetcode.com/problems/rotated-digits

class Solution {
public:
    int rotatedDigits(int N) {
        vector<int> f({1,1,2,0,0,2,2,0,1,2});
        int res = 0;
        
        for(int i = 1; i <= N; i++){
            int p = i;
            int s = 1;
            
            while(p){
                s *= f[p % 10];
                p /= 10;
            }
            if(s >=2) 
                res++;
        }
        
        return res;
    }
};
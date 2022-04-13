// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        
        int countEven = 0, countOdd = 0, sum = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum = (sum + arr[i]) % 2;
            if(sum == 0) /* sum is even */
            {
                ans = ans + countOdd;                
                countEven = (countEven + 1) % 1000000007;
            }
            else /* sum is odd */
            {
                ans = ans + 1 + countEven;
                countOdd = (countOdd + 1) % 1000000007;
            }
            ans %= 1000000007;
        }
        return ans;
    }
};
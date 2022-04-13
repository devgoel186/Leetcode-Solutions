// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n, 0);
        
        if(n <= 2)
            return 0;
        
        for(int i = 1; i < n; i++)
        {
            diff[i] = nums[i] - nums[i - 1];
        }
        
        int count = 2, sum = 0;
        for(int i = 2; i < n; i++)
        {
            if(diff[i] == diff[i - 1])
                count++;
            
            else
            {
                if(count >= 3)
                    sum += ((count - 1) * (count - 2)) / 2;
                
                count = 2;
                i++;
            }
            
            cout << count << endl;
        }
        
        cout << count << endl;
        
        if(count >= 3)
        {
            sum += ((count - 1) * (count - 2)) / 2;
        }
        
        return sum;
    }
};
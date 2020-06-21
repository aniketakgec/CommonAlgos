//LEETCODE SOLUTION for LONGEST INCREASING SUBSEQUENCE

class Solution {
public:
    int LIS(vector<int>&nums)
    {
        int n=nums.size();
        if(n==0)
         return 0;
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]>=nums[i])
                    continue;
                else
                {  
// if answer till here is increasing then add 1 to it to make possible answer for dp[i]       
                    int possibleAnswer=dp[j]+1;
                    
                    if(possibleAnswer>dp[i])
                        dp[i]=possibleAnswer;
                    
                }
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++)
            res=max(res,dp[i]);
        
        return res;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        return LIS(nums);
        
    }
};
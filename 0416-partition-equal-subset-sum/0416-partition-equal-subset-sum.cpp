class Solution {
public:

    bool calc(int i,int sum,vector<int>& nums){
        if(sum==0)
        {
            return true;
        }
        if(i==0)
        {
            if(sum==nums[0])
            {
                return true;
            }
            else{
                return false;
            }
        }
        int np=calc(i-1,sum,nums);
        int pick=false;
        if(sum>=nums[i])
        {
            pick=calc(i-1,sum-nums[i],nums);
        }
        return pick|np;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        sum=sum/2;

        vector<vector<int>>dp(n,vector<int>(sum+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool np=dp[i-1][target];
                bool p=false;
                if(target>=nums[i])
                {
                    p=dp[i-1][target-nums[i]];
                }
                dp[i][target]=p|np;
            }
        }
        return dp[n-1][sum];
    }
};
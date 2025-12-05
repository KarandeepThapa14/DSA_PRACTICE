class Solution {
public:
    int helper(vector<int>& nums,int k)
    {
        if(k<0){return 0;}
        int r=0,l=0,sum=0;
        int ans=0;
        while(r<nums.size())
        {
            sum+=nums[r];
           
            while(sum>k)
            {
                sum-=nums[l];
                l++;
            }
            
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=helper(nums,goal)-helper(nums,goal-1);
        return ans;
    }
};
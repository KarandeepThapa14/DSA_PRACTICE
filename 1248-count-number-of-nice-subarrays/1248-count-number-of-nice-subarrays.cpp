class Solution {
public:
    int helper(vector<int>& nums,int k)
    {
        int c=0,l=0,r=0,ans=0;
        while(r<nums.size()){
            if(nums[r]%2!=0)
            {
                c++;
            }
            while(c>k)
            {
                if(nums[l]%2!=0)
                {
                    c--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=helper(nums,k)-helper(nums,k-1);
        return ans;
    }
};
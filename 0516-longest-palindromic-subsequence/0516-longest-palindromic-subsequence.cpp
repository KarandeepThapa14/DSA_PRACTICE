class Solution {
public:
    int calc(int i,int j,string &s,vector<vector<int>> &dp)
    {
        if(i>j){
            return 0;
        }

        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]= 2+calc(i+1,j-1,s,dp);
        }

        return dp[i][j]= max(calc(i+1,j,s,dp),calc(i,j-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int ans=calc(0,s.size()-1,s,dp);
        return ans;
    }
};
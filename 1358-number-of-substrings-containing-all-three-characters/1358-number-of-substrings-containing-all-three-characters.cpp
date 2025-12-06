class Solution {
public:
    bool satisfies(map<char,int>&freq){
        if(freq['a']>0 && freq['b']>0 && freq['c']>0)
        {
            return true;
        }
        return false;
    }
    int numberOfSubstrings(string s) {
        int total=0;
        for(int i=1;i<=s.size();i++)
        {
            total+=i;
        }
        int r=0,l=0,ans=0;
        map<char,int>freq;
        while(r<s.size())
        {
            freq[s[r]]++;
            while(satisfies(freq))
            {
                freq[s[l]]--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        cout<<ans<<" "<<total;

        return total-ans;
    }
};
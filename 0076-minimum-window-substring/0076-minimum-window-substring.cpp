class Solution {
public:
    string minWindow(string s, string t) {
        int count=0;
        int l=0,r=0;
        vector<int>freq(128,0);
        for(int i=0;i<t.size();i++)
        {
            freq[t[i]]++;
        }
        int minlength=INT_MAX;
        int best=0;
        while(r<s.size())
        {
            
            if(freq[s[r]]>0)
            {
                count++;
            }
            freq[s[r]]--;
            while(count==t.size())
            {
                if(r-l+1<minlength)
                {
                    minlength=r-l+1;
                    best=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0)
                {
                    count--;
                }
               
                l++;
            }
            r++;
        }

        if(minlength==INT_MAX)
        {
            return "";
        }
        return s.substr(best,minlength);
    }
};
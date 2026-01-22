class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        
        for(auto it:mp)
        {
            pair<int,char>p;
            p.first=it.second;
            p.second=it.first;
            v.push_back(p);
        }
        string ans;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
       for(auto it:v)
       {
            for(int i=0;i<it.first;i++)
            {
                ans+=it.second;
            }
       }

        return ans;
    }
};
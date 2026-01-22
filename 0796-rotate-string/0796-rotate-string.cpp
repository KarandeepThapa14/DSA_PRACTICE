#include <bits/stdc++.h>
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)
        {
            return true; 
        }
        string temp=s;
        std::rotate(temp.begin(),temp.begin()+1,temp.end());
        while(temp!=s)
        {
            if(temp==goal)
            {
                return true;
            }
            else{
                std::rotate(temp.begin(),temp.begin()+1,temp.end());
            }
        }
        return false;
    }
};
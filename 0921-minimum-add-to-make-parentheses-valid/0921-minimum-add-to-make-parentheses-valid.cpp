class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            if(s[i]==')' && st.empty())
            {
                count++;
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
        }
        return count+st.size();
    }
};
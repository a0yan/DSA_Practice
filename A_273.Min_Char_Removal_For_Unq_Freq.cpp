class Solution 
{
public:
    string removeKdigits(string num, int k)
    {
        if(num.length() == k)
            return("0");
        
        stack<char> s;
        
        for(int i = 0;i<num.length();i++)
        {
            while(!s.empty() && s.top() > num[i] && k>0)
            {
                s.pop();
                k-=1;
            }
            s.push(num[i]);
        }
        
        while(k>0)
        {
            s.pop();
            k-=1;
        }
        
        string ans="";
        
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        int len=ans.size();
        while(ans.size()>1&&ans[len-1]=='0')
        {//remove leading zeros
            ans.pop_back();
            len--;
    }
        reverse(ans.begin(),ans.end());
        return ans;
 
        
    }
};

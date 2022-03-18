class Solution {
public:
    string removeDuplicateLetters(string str) {
        vector<int>taken(26,0);
        unordered_map<char,int>mp;
        stack<char>s;
        string ans="";
        
        for(char xx : str)
            mp[xx]++;
        
        for(char xx : str)
        {
            if(s.empty())
            {
                s.push(xx);
                taken[xx-'a']=1;
            }
            else
            {
                if(s.top()>xx)
                {
                    if(taken[xx-'a']==0)
                    {
                        while(!s.empty() && s.top()>xx && mp[s.top()]>=1)
                        {
                            taken[s.top()-'a']=0;
                            s.pop();
                        }
                        
                        s.push(xx);
                        taken[xx-'a']=1;
                    }
                }
                else
                {
                    if(taken[xx-'a']==0)
                    {
                        s.push(xx);
                        taken[xx-'a']=1;
                    }
                }
            }
            
            mp[xx]--;
        }
        
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
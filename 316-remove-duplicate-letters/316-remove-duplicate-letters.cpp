class Solution {
public:
    string removeDuplicateLetters(string str) {
        
        // tracks whether the current character is included in our current answer string
        vector<int>taken(26,0);
        // keeps remaining frequency of characters
        unordered_map<char,int>mp;
        // monotonic stack
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
                // if not in dictionary order
                if(s.top()>xx)
                {
                    if(taken[xx-'a']==0)
                    {
                        // while character not in dictionary order & their duplicates are present
                        while(!s.empty() && s.top()>xx && mp[s.top()]>=1)
                        {
                            taken[s.top()-'a']=0;
                            s.pop();
                        }
                        
                        s.push(xx);
                        taken[xx-'a']=1;
                    }
                }
                // already in dictionary order
                else
                {
                    // if not included in our answer already
                    if(taken[xx-'a']==0)
                    {
                        s.push(xx);
                        taken[xx-'a']=1;
                    }
                }
            }
            
            // update the remaining frequency of characters
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
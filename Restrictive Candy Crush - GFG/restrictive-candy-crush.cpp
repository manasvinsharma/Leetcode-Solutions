// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k, string &s){
        // Your code goes here
        string ans="";
        stack<pair<char,int>>stk;
        
        int i=0, n=s.size();
    
        while(i<n)
        {
            int j = i+1, count=1;
            char prev = s[i];
            
            while(j<n && s[j]==prev)
            {
                j++;
                count++;
            }
            
            // cout<<prev<<" "<<count<<"\n";
            
            if(!stk.empty() && stk.top().first == prev)
            {
                count+=stk.top().second;
                
                if(count>=k)
                {
                    int rem = count % k;
                    if(rem==0)
                    {
                        stk.pop();
                    }
                    else
                    {
                        stk.pop();
                        stk.push({prev, rem});
                    }
                }
                else
                {
                    stk.pop();
                    stk.push({prev, count});
                }
            }
            else
            {
                if(count>=k)
                {
                    int rem = count%k;
                    
                    if(rem!=0)
                    {
                        stk.push({prev, rem});
                    }
                }
                else
                {
                    stk.push({prev, count});
                }
            }
            
            i = j;
        }
        
        while(!stk.empty())
        {
            string temp="";
            char ch = stk.top().first;
            int freq = stk.top().second;
            stk.pop();
            
            for(int i=0;i<freq;i++)
            temp+=ch;
            
            ans+=temp;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends
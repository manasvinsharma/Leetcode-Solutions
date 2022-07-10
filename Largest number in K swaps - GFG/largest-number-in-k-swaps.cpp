// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    string ans;
    
    void solve(string &str, int k, int curr)
    {
        int n = str.size();
        
        if(str > ans)
        ans = str;
        
        // if swaps become zero or if we reach the end of string
        if(k==0 || curr==n)
        return ;
        
        // optimization
        // if already a bigger number is found then no need to go with a smaller number
        if(curr!=0 && ans[curr-1]>str[curr-1])
        return ;
        
        for(int i=curr;i<n;i++)
        {
            swap(str[i], str[curr]);
            
            if(curr!=i)
            solve(str, k-1, curr+1);
            else
            solve(str, k, curr+1);
            
            swap(str[i], str[curr]);
        }
        return ;
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string &str, int k)
    {
       // code here
       int n = str.size();
       
       // create a dummy string just to compare
       for(int i=0;i<n;i++)
       ans+="0";
       
       solve(str, k, 0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
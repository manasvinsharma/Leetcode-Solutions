// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    bool XKnowsY(int x, int y, vector<vector<int> >& M)
    {
        // means x knows y
        if(M[x][y]==1)
        return true;
        
        return false;
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        queue<int>q;
        
        for(int i=0;i<n;i++)
        q.push(i);
        
        while(q.size()>1)
        {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
        
            if(XKnowsY(x,y,M))
            q.push(y);
            else
            q.push(x);
        }
    
        int possibleCeleb = q.front();
        q.pop();
    
        int zero=0, ones=0;
    
        for(int i=0;i<M.size();i++)
        {
            if(M[possibleCeleb][i]==0)
            zero++;
        }
    
        for(int i=0;i<M.size();i++)
        {
            if(M[i][possibleCeleb]==1)
            ones++;
        }
    
        if(zero == M.size() && ones == M.size()-1)
        return possibleCeleb;
        else
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
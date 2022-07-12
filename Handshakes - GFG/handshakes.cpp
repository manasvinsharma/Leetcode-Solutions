// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    // catlan number variation dynamic programming
    // similar question to the Non Intersecting Chords in polygon
    int count(int &n){
        // code here
        if(n&1)
        return 0;
        
        // doing this because
        // Catlan number        people for handshakes
        // c1                   2
        // c2                   4
        // c3                   6
        // and for odd number of people answer is always 0
        n = n/2;
        
        vector<int>dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];
    }
};
// dp[4] = dp[0]*dp[3] + dp[1]*dp[2] + dp[2]*dp[1] + dp[3]*dp[0]


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
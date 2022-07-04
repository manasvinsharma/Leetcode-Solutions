// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    vector<long long>v1,v2;
    
    // 6  2  5  4  5  1  6
    // 0  1  2  3  4  5  6
    
    // 1  5  3  5  5  7  7
    //-1 -1  1  1  3 -1  5
    
    // 6 10  5  12 5  7  6
    
    void nextSmallerElement(long long arr[], int &n)
    {
        stack<pair<long long, int>>s;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                v1.push_back(n);
                s.push({arr[i],i});
            }
            else
            {
                while(!s.empty() && s.top().first >= arr[i])
                s.pop();
                
                if(s.empty())
                {
                    v1.push_back(n);
                }
                else
                {
                    v1.push_back(s.top().second);
                }
                
                s.push({arr[i],i});
            }
        }
        
        // for(int xx : v1)
        // cout<<xx<<" ";
        // cout<<"\n";
        
        reverse(v1.begin(),v1.end());   
        return ;
    }
    
    void previousSmallerElement(long long arr[], int &n)
    {
        stack<pair<long long, int>>s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                v2.push_back(-1);
                s.push({arr[i],i});
            }
            else
            {
                while(!s.empty() && s.top().first >= arr[i])
                s.pop();
                
                if(s.empty())
                {
                    v2.push_back(-1);
                }
                else
                {
                    v2.push_back(s.top().second);
                }
                
                s.push({arr[i],i});
            }
        }
    
        // for(int xx : v2)
        // cout<<xx<<" ";
        // cout<<"\n";
    
        return ;
    }    

    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxArea=-1;
        vector<long long>width(n,0);
        nextSmallerElement(arr,n);
        previousSmallerElement(arr,n);
        
        for(int i=0;i<n;i++)
        {
            width[i] = abs(v1[i]-v2[i])-1;
        }
        
        for(int i=0;i<n;i++)
        {
            long long area = width[i] * arr[i];
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
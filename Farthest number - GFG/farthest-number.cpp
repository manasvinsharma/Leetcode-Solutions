// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

// 3, 1, 5, 2, 4 Arr
// 1, 1, 2, 2, 4 Smallest array
// Smallest array keeps the "smallest number" present on right of each element in whole array
// then we apply BS on smallest array & find the farthest index. Smallest array will always be in sorted order.
class Solution{   
  public:
    int binary_search(int low, int high, vector<int>& smallest, int val)
    {
        int mid;
        int farthestInd = -1;
        
        while(high >= low)
        {
            mid = (high-low)/2 + low;
            
            if(smallest[mid] < val)
            {
                farthestInd = max(mid, farthestInd);
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return farthestInd;
    }
  
    vector<int> farNumber(int N,vector<int> arr){
        //code here
        int n = arr.size();
        vector<int>smallest(n,INT_MAX);
        vector<int>ans(n,0);
        
        smallest[n-1] = arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            smallest[i] = min(arr[i], smallest[i+1]);
        }
        
        // for(int xx : smallest)
        // cout<<xx<<" ";
        
        // cout<<"\n";
        
        ans[n-1] = -1;
        
        for(int i=0;i<n-1;i++)
        {
            int ind = binary_search(i+1, n-1, smallest, arr[i]);
            ans[i] = ind;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends
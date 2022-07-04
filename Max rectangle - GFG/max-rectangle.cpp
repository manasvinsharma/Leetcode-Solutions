// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/
class Solution{
  public:
  
    vector<int>v1,v2;
    
    void nextSmallerElement(int arr[], int &n)
    {
        stack<pair<int, int>>s;
        
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
    
    void previousSmallerElement(int arr[], int &n)
    {
        stack<pair<int, int>>s;
        
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
    int MAH(int arr[], int n)
    {
        // Your code here
        int maxArea=0;
        vector<int>width(n,0);
        
        v1.clear();
        nextSmallerElement(arr,n);
        
        v2.clear();
        previousSmallerElement(arr,n);
        
        for(int i=0;i<n;i++)
        {
            width[i] = abs(v1[i]-v2[i])-1;
        }
        
        for(int i=0;i<n;i++)
        {
            int area = width[i] * arr[i];
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
  
    int maxArea(int M[MAX][MAX], int m, int n) {
        // Your code here
        int ans = INT_MIN, temp;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=0)
                {
                    if(M[i][j]!=0)
                    M[i][j]+=M[i-1][j];
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            temp = MAH(M[i],n);
            ans = max(ans,temp);
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
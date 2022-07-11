// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    unordered_set<int>visited;
 
 // 1-> 2
 // 2-> 1, 3, 4
 // 3-> 2
 // 4-> 2
    
    bool solve(vector<int> arr[] , int curr, int count, int &n)
    {
        if(count == n)
        return true;
        
        for(int child : arr[curr])
        {
            if(visited.find(child) == visited.end())
            {
                visited.insert(child);
                
                if(solve(arr, child, count+1, n))
                return true;
                
                visited.erase(child);
            }
        }
        
        return false;
    }
    
    bool check(int n,int m,vector<vector<int>> edges)
    {
        // code here
        vector<int> arr[n+1]; 
        
        for(int i=0;i<m;i++)
        {
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(visited.find(i) == visited.end())
            {
                visited.insert(i);
                
                if(solve(arr,i,1,n))
                {
                    // cout<<i<<"\n";
                    return true;
                }
                
                visited.erase(i);
            }
        }
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends
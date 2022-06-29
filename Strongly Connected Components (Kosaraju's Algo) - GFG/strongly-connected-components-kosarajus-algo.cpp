// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	stack<int>s;
	unordered_set<int>visited;
	
	void DFS(int node, vector<int> adj[])
	{
	    for(int child : adj[node])
	    {
	        if(visited.find(child)==visited.end())
	        {
	            visited.insert(child);
	            DFS(child,adj);
	            s.push(child);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        int components=0;
        
        for(int i=0;i<v;i++)
        {
            if(visited.find(i)==visited.end())
            {
                visited.insert(i);
                DFS(i,adj);
                s.push(i);
            }
        }
        
        // print toposort
        // while(!s.empty())
        // {
        //     cout<<s.top()<<" ";
        //     s.pop();
        // }
        
        vector<int> transpose[v];
        
        for(int i=0;i<v;i++)
        {
            for(int x : adj[i])
            {
                transpose[x].push_back(i);
            }
        }
        
        visited.clear();
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            if(visited.find(node)==visited.end())
            {
                visited.insert(node);
                DFS(node,transpose);
                components++;
            }
        }
        
        return components;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
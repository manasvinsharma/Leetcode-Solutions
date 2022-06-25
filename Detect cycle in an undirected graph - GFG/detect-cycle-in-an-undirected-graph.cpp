// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    unordered_set<int>visited;
    
    bool cyclePresent(int node, vector<int> adj[])
    {
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty())
        {
            int parent = q.front().second;
            int node = q.front().first;
            q.pop();
            visited.insert(node);
            
            for(int child : adj[node])
            {
                if(child!=parent)
                {
                    if(visited.find(child)!=visited.end())
                    {
                        return true;
                    }
                    else
                    {
                        q.push({child,node});
                    }
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        for(int i=0;i<v;i++)
        {
            if(visited.find(i)==visited.end())
            {
                if(cyclePresent(i,adj))
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
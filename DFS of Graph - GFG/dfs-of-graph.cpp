// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    unordered_set<int>visited;
    vector<int>ans;
    
    void DFS(int node, vector<int> adj[])
    {
        for(int child : adj[node])
        {
            if(visited.find(child)==visited.end())
            {
                visited.insert(child);
                ans.push_back(child);
                DFS(child, adj);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        for(int i=0;i<V;i++)
        {
            if(visited.find(i)==visited.end())
            {
                visited.insert(i);
                ans.push_back(i);
                DFS(i,adj);
            }
        }
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    unordered_set<int>visited;
    vector<int>ans;
    
    void BFS(int node, vector<int> adj[])
    {
        queue<int>q;
        q.push(node);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int child : adj[node])
            {
                if(visited.find(child)==visited.end())
                {
                    visited.insert(child);
                    ans.push_back(child);
                    q.push(child);
                }
            }
        }
    }
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        visited.insert(0);
        ans.push_back(0);
        BFS(0,adj);
        // for(int i=0;i<V;i++)
        // {
        //     if(visited.find(i)==visited.end())
        //     {
        //         visited.insert(i);
        //         ans.push_back(i);
        //         BFS(i,adj);
        //     }
        // }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
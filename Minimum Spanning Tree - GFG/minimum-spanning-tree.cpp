// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        vector<bool>inc(v,false);
        vector<int>parent(v,-1);
        vector<int>key(v,INT_MAX);
        int sum=0;
        
        // {weight, node}
        pq.push({0,0});
        key[0]=0;
        
        while(!pq.empty())
        {
            int val = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            inc[node] = true;
            
            for(vector<int> child : adj[node])
            {
                // child node
                int childNode = child[0];
                // weight of the edge connecting child node & parent node
                int weight = child[1];
                
                if(inc[childNode]==false && key[childNode]>weight)
                {
                    key[childNode] = weight;
                    parent[childNode] = node;
                    pq.push({weight,childNode});
                }
            }
        }
        
        for(int x : key)
        sum+=x;
        
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
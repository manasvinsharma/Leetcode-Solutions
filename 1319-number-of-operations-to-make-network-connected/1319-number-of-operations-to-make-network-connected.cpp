class Solution {
public:
    unordered_set<int>visited;
    
    void DFS(int node, vector<int> arr[])
    {
        for(int child : arr[node])
        {
            if(visited.find(child)==visited.end())
            {
                visited.insert(child);
                DFS(child,arr);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>> &connections) {
        int components=0, edges=connections.size();
        
        vector<int>arr[n];
        
        for(auto vec : connections)
        {
            arr[vec[0]].push_back(vec[1]);
            arr[vec[1]].push_back(vec[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited.find(i)==visited.end())
            {
                visited.insert(i);
                DFS(i,arr);
                components++;
            }
        }
        
        if(edges < (n-1))
            return -1;
        else
            return components-1;
    }
};
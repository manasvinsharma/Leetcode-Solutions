// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int visited[10][10];
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    char mv[4] = {'R', 'L', 'D', 'U'};
    vector<string>ans;
    
    bool isValid(int x, int y, int n)
    {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    
    void DFS(vector<vector<int>> &m, int x, int y, int n, string str)
    {
        if(x == n-1 && y == n-1 && m[x][y] == 1)
        {
            ans.push_back(str);
            return ;
        }
        
        for(int i=0;i<4;i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(isValid(newx,newy,n) && visited[newx][newy] == 0 && m[newx][newy] == 1)
            {
                visited[newx][newy] = 1;
                DFS(m,newx,newy,n,str+mv[i]);
                visited[newx][newy] = 0;
            }
        }
        return ;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int &n) {
        // Your code goes here
        memset(visited,0,sizeof(visited));
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
        return ans;
        
        visited[0][0] = 1;
        DFS(m,0,0,n,"");
        visited[0][0] = 0;
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
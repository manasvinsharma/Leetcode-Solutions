// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int visited[500][500];
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
  
    bool check(int x, int y, int m, int n)
    {
        return(x>=0 && x<m && y>=0 && y<n);
    }
  
    void BFS(int i, int j, int m, int n, vector<vector<char>> &grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j] = 1;
        grid[i][j] = 'x';
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0;k<8;k++)
            {
                int newx = x+dx[k];
                int newy = y+dy[k];
                
                if(check(newx,newy,m,n) && grid[newx][newy]=='1' && visited[newx][newy]==0)
                {
                    q.push({newx,newy});
                    visited[newx][newy] = 1;
                    grid[newx][newy] = 'x';
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        int m = grid.size();
        int n = grid[0].size();
        
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    BFS(i,j,m,n,grid);
                    ans++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
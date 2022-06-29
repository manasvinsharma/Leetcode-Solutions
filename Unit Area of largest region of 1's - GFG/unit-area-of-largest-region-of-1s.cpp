// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
    
    bool isValid(int x, int y, int m ,int n)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    
    int BFS(int i, int j, vector<vector<int>> &grid)
    {
        int ans=0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        
        q.push({i,j});
        grid[i][j]=-1;
        ans++;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            for(int k=0;k<8;k++)
            {
                int newx = dx[k] + x;
                int newy = dy[k] + y;
                    
                if(isValid(newx,newy,m,n) && grid[newx][newy]==1)
                {
                    q.push({newx,newy});
                    grid[newx][newy]=-1;
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans = max(BFS(i,j,grid),ans);
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
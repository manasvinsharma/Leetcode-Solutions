// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int visited[501][501];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool check(int x, int y, int n)
    {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    
    bool BFS(int n, pair<int,int> &start, pair<int,int> &end, vector<vector<int>> &grid)
    {
        queue<pair<int,int>>q;
        q.push(start);
        visited[start.first][start.second] = 1;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            if(x == end.first && y== end.second)
            return true;
            
            for(int k=0;k<4;k++)
            {
                int newx = x + dx[k];
                int newy = y + dy[k];
                
                if(check(newx,newy,n) && visited[newx][newy]==0 && grid[newx][newy]!=0)
                {
                    q.push({newx,newy});
                    visited[newx][newy] = 1;
                }
            }
        }
        
        return false;
    }
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid) 
    {
        //code here
        int n = grid.size();
        pair<int,int>start,end;
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                start = {i,j};
                
                else if(grid[i][j]==2)
                end = {i,j};
            }
        }
        
        return BFS(n,start,end,grid);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
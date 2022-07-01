// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int arr[1001][1001];
    
    bool check(int x, int y, int n)
    {
        return (x>=1 && x<=n && y>=1 && y<=n);
    }
    
    int BFS(vector<int> &start, vector<int> &end, int &n)
    {
        queue<vector<int>>q;
        
        q.push({start[0],start[1],0});
        arr[start[0]][start[1]]=1;
        
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            int ans = q.front()[2];
            q.pop();
            
            if(x==end[0] && y==end[1])
            return ans;
            
            if(check(x-1,y+2,n) && arr[x-1][y+2]==0)
            {
                q.push({x-1,y+2,ans+1});
                arr[x-1][y+2]=1;
            }
            if(check(x-1,y-2,n) && arr[x-1][y-2]==0)
            {
                q.push({x-1,y-2,ans+1});
                arr[x-1][y-2]=1;
            }
            if(check(x+1,y+2,n) && arr[x+1][y+2]==0)
            {
                q.push({x+1,y+2,ans+1});
                arr[x+1][y+2]=1;
            }
            if(check(x+1,y-2,n) && arr[x+1][y-2]==0)
            {
                q.push({x+1,y-2,ans+1});
                arr[x+1][y-2]=1;
            }
            
            if(check(x+2,y-1,n) && arr[x+2][y-1]==0)
            {
                q.push({x+2,y-1,ans+1});
                arr[x+2][y-1]=1;
            }
            if(check(x-2,y-1,n) && arr[x-2][y-1]==0)
            {
                q.push({x-2,y-1,ans+1});
                arr[x-2][y-1]=1;
            }
            if(check(x+2,y+1,n) && arr[x+2][y+1]==0)
            {
                q.push({x+2,y+1,ans+1});
                arr[x+2][y+1]=1;
            }
            if(check(x-2,y+1,n) && arr[x-2][y+1]==0)
            {
                q.push({x-2,y+1,ans+1});
                arr[x-2][y+1]=1;
            }
        }
        return -1;
    }
    
	int minStepToReachTarget(vector<int> start, vector<int> end, int n){
	    // Code here
	    memset(arr,0,sizeof(arr));
	    return BFS(start,end,n);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
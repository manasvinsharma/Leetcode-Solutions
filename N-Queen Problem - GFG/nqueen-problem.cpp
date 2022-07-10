// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int visited[11][11];
    vector<vector<int>>ans;

    bool check(int row, int col, int &n)
    {
        int i = row, j = col;
        
        // up-left diagonal
        while(i>=0 && j>=0)
        {
            i--,j--;
            if(visited[i][j]==1)
            return false;
        }
        
        i = row, j = col;
        
        // up-right diagonal
        while(i>=0 && j<n)
        {
            i--,j++;
            if(visited[i][j]==1)
            return false;
        } 
        
        i = row;
        
        // vertically up
        while(i>=0)
        {
            i--;
            if(visited[i][col]==1)
            return false;
        }
        
        return true;
    }

    void solve(int &n, int row)
    {
        // if reached here means that we are able to set all queens
        if(row == n)
        {
            // saving the current answer
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(visited[i][j] == 1)
                    {
                        temp.push_back(j+1);
                    }
                }
            }
            
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[row][i] == 0 && check(row,i,n))
            {
                visited[row][i] = 1;
                solve(n, row+1);
                visited[row][i] = 0;
            }
        }
        return ;
    }

    vector<vector<int>> nQueen(int &n) {
        // code here
        memset(visited, 0, sizeof(visited));
        
        solve(n, 0);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
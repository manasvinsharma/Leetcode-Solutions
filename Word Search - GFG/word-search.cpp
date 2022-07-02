// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int visited[101][101];
    unordered_map<char, vector<pair<int,int>>>mp;
    
    bool DFS(vector<vector<char>>& board, string &word, int i, int x, int y)
    {
        if(i==word.size()-1 && board[x][y]==word[i])
        return true;
        else if(i==word.size() && board[x][y]!=word[i])
        return false;
        
        for(pair<int,int> pr : mp[word[i+1]])
        {
            if(visited[pr.first][pr.second]==0 && (abs(x-pr.first)+abs(y-pr.second))<=1)
            {
                visited[pr.first][pr.second] = 1;
            
                if(DFS(board, word, i+1, pr.first, pr.second))
                return true;
                
                visited[pr.first][pr.second] = 0;
            }
        }
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string &word) {
        // Code here
        int n = word.size();
        int row = board.size(), col = board[0].size();
        
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mp[board[i][j]].push_back({i,j});
            }
        }
        
        for(pair<int,int>pr : mp[word[0]])
        {
            if(visited[pr.first][pr.second]==0)
            {
                visited[pr.first][pr.second] = 1;
            
                if(DFS(board, word, 0, pr.first, pr.second))
                return true;
                
                visited[pr.first][pr.second] = 0;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
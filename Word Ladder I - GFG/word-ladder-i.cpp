// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    unordered_map<string, vector<string>>mp;
    unordered_set<string>visited;
    
    // apply BFS to find shotest path (minimum steps needed to reach targetWord from startWord)
    int BFS(string &str, string &targetWord, vector<string> &wordList)
    {
        queue<pair<string,int>>q;
        
        q.push({str,0});
        visited.insert(str);
        
        while(!q.empty())
        {
            string node = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(node == targetWord)
            return steps+1;
            
            for(string child : mp[node])
            {
                if(visited.find(child)==visited.end())
                {
                    q.push({child,steps+1});
                    visited.insert(child);
                }
            }
        }
        
        // if not possible to reach at targetWord
        return INT_MAX;
    }
    
    int wordLadderLength(string &startWord, string &targetWord, vector<string> &wordList) {
        // Code here
        int ans = INT_MAX;
        
        // create a graph
        for(string str1 : wordList)
        {
            for(string str2 : wordList)
            {
                if(str1!=str2 && str1.size()==str2.size())
                {
                    int n = str1.size(), diff=0;
                    for(int i=0;i<n;i++)
                    {
                        if(str1[i]!=str2[i])
                        diff++;
                        
                        if(diff>1)
                        break;
                    }
                    
                    if(diff==1)
                    {
                        mp[str1].push_back(str2);
                    }
                }
            }
        }
        
        // try to start BFS with each node of graph (if possible)
        for(string str : wordList)
        {
            if(str.size() == startWord.size())
            {
                int n = str.size(), diff=0;
                for(int i=0;i<n;i++)
                {
                    if(str[i]!=startWord[i])
                    diff++;
                    
                    if(diff>1)
                    break;
                }
                
                if(diff==1)
                {
                    visited.clear();
                    int val = BFS(str,targetWord,wordList);
                    
                    if(val!=INT_MAX)
                    val++;
                    
                    ans = min(val,ans);
                }
                // handles if startWord is already present in our Graph (wordList)
                else if(diff==0)
                {
                    visited.clear();
                    int val = BFS(str,targetWord,wordList);
                    
                    ans = min(val,ans);
                }
            }
        }
        
        if(ans==INT_MAX)
        return 0;
        else
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
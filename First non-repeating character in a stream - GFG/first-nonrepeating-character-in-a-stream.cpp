// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue<char>q;
		    vector<int>mp(26,0);
		    string ans="";
		    
		    for(char xx : s)
		    {
		        mp[xx-'a']++;
		        
		        if(mp[xx-'a']==1)
		        {
		            q.push(xx);
		        }
		        else
		        {
		            if(!q.empty() && q.front()==xx)
		            q.pop();
		        }
		        
		        
		        while(!q.empty() && mp[q.front()-'a']!=1)
		            q.pop();
		        
		        if(!q.empty())
		        ans+=q.front();
		        else
		        ans+="#";
		    }
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<string>ans;
	unordered_map<string, bool>mp;
	    
	void solve(string str, int curr, int n)
	{
	    if(curr==n)
	    {
	        if(mp.find(str)==mp.end())
	        {
	            ans.push_back(str);
	            mp[str] = true;
	        }
	        return ;
	    }
	    
	    for(int i=curr;i<n;i++)
	    {
	        swap(str[i], str[curr]);
	        solve(str,curr+1,n);
	    }
	    
	    return ;
	}
	    
	vector<string>find_permutation(string str)
	{
	    // Code here there
	    sort(str.begin(), str.end());
	    
	    int n = str.size();
	    solve(str,0,n);
	    
	    return ans;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
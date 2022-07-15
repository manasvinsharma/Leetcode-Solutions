// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_set<string>s;

    bool solve(string &A, int start)
    {
        if(start == A.size())
        return true;
        
        for(int i=start; i<A.size(); i++)
        {
            string left = A.substr(start,i-start+1);
            if(s.find(left) != s.end())
            {
                // string right = A.substr(i+1, A.size());
                if(solve(A, i+1))
                return true;
            }
        }
        return false;
    }

    int wordBreak(string &A, vector<string> &B) {
        //code here
        for(string x : B)
        s.insert(x);
        
        return solve(A, 0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends
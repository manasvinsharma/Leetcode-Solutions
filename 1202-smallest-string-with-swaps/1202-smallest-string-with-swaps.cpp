// logic - all the characters which can be somehow swapped with each other form a graph component.
// thus, any characters in a component can be swapped with any other character in that component.

class Solution {
public:
    unordered_map<int,int>mp;
    
    // normal DFS
    void DFS(int parent, vector<int>arr[], string &s, vector<int>&ind, vector<char>&ch)
    {
        // save the index 
        ind.push_back(parent);
        // save the character corresponding to the index
        ch.push_back(s[parent]);
        
        mp[parent] = 1;
        
        for(int child : arr[parent])
        {
            if(mp.find(child)==mp.end())
                DFS(child,arr,s,ind,ch);
        }
    }
    
    string smallestStringWithSwaps(string &s, vector<vector<int>>& pairs) {
        int n = s.size(), edges = pairs.size();
        vector<int>arr[n];
        
        // create adjacency list
        for(int i=0;i<edges;i++)
        {   
            arr[pairs[i][0]].push_back(pairs[i][1]);
            arr[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                vector<char>ch;
                vector<int>ind;
                
                DFS(i,arr,s,ind,ch);
                
                // sort both arrays
                sort(ch.begin(),ch.end());
                sort(ind.begin(),ind.end());
                
                int sz = ind.size();
                // update the string
                for(int i=0;i<sz;i++)
                {
                    s[ind[i]] = ch[i];
                }
            }
        }
        return s;
    }
};
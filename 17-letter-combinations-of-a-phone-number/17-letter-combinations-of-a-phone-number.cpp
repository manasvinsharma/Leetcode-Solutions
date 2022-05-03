class Solution {
public:
    vector<string>mp{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>ans;
    
    void solve(string &digits, string temp, int curr , int n)
    {
        if(curr >= n)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(char ch : mp[digits[curr]-'2'])
        {
            temp+=ch;
            solve(digits,temp,curr+1,n);
            temp.pop_back();
        }
        
        return ;
    }
    
    vector<string> letterCombinations(string &digits) {
        int n = digits.size();
        string temp="";
        
        if(n==0)
        {
            return ans;
        }
        
        solve(digits,temp,0,n);
        
        return ans;
    }
};
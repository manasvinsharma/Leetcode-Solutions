class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    
    void backtrack(vector<int>&nums, vector<int>temp, int curr, int &n)
    {   
        if(temp.size()>1 && s.find(temp)==s.end())
        {
            ans.push_back(temp);
            s.insert(temp);
        }
        
        if(curr == n)
            return ;
        
        for(int i=curr;i<n;i++)
        {
            if(temp.size()==0)
            {
                temp.push_back(nums[i]);
                backtrack(nums,temp,i+1,n);
                temp.pop_back();
            }
            else
            {
                if(temp.back()<=nums[i])
                {
                    temp.push_back(nums[i]);
                    backtrack(nums,temp,i+1,n);
                    temp.pop_back();
                }
            }
        }
        return ;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size(), curr=0;
        vector<int>temp;
        
        backtrack(nums,temp,curr,n);
        
        return ans;
    }
};
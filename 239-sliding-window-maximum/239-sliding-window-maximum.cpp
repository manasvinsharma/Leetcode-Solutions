class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<pair<int,int>>q;
        int n = nums.size();
        
        for(int i=0;i<k;i++)
        {
            if(q.empty())
            {
                q.push_back({nums[i],i});
            }
            else
            {
                if(nums[i]<q.back().first)
                {
                    q.push_back({nums[i],i});
                }
                else
                {
                    while(!q.empty() && q.back().first<=nums[i])
                        q.pop_back();
                    
                    q.push_back({nums[i],i});
                }
            }
        }
        
        ans.push_back(q.front().first);
        
        for(int i=k;i<n;i++)
        {
            if(q.front().first==nums[i-k] && q.front().second==(i-k))
            q.pop_front();
            
            if(q.empty())
            {
                q.push_back({nums[i],i});
            }
            else
            {
                if(nums[i]<q.back().first)
                {
                    q.push_back({nums[i],i});
                }
                else
                {
                    while(!q.empty() && q.back().first<=nums[i])
                        q.pop_back();
                    
                    q.push_back({nums[i],i});
                }
            }
            
            ans.push_back(q.front().first);
        }
        
        return ans;
    }
};
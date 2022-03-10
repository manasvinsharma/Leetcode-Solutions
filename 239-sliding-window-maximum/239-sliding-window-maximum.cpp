// Think for this testcase
// [1,3,-1,-3,5,3,6,7]
// k = 3
// ans = [3,3,5,5,6,7]

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<pair<int,int>>q;
        int n = nums.size();
        
        // create a window of size k
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
        
        // start moving the window by 1 
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
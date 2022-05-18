// -4 -1 1 2

//     diff=4
//     ans=-3
    
    

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(),j,k,i=0,first,sec,third,diff=INT_MAX,ans;
        sort(nums.begin(),nums.end());
        
        while(i<(n-2))
        {
            j=i+1;
            k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]>target)
                {
                    if( (abs(target-(nums[i]+nums[j]+nums[k]))) < diff )
                    {
                        diff = abs(target-(nums[i]+nums[j]+nums[k])); 
                        ans = (nums[i]+nums[j]+nums[k]);
                    }
                    
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<target)
                {
                    if( (abs(target-(nums[i]+nums[j]+nums[k]))) < diff )
                    {
                        diff = abs(target-(nums[i]+nums[j]+nums[k])); 
                        ans = (nums[i]+nums[j]+nums[k]);
                    }
                    
                    j++;
                }
                else
                {

                    diff = 0;
                    ans = target;               
                    
                    sec=nums[j],third=nums[k];
                    
                    // while nums[j] is equal to second increment j. This is done for optimize
                    while(j<n && sec==nums[j])
                        j++;
                    
                    // while nums[k] is equal to third decrement k. This is done for optimize
                    while(k>=0 && third==nums[k])
                        k--;
                }
            }
            
            first = nums[i];
                    // while nums[i] is equal to first increment i. This is done for optimize
            while(i<n && first==nums[i])
                i++;
        }
        
        return ans;
    }
};
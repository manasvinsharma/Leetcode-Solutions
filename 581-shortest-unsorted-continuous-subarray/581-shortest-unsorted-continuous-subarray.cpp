class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxElement=-1e5-1,minElement=1e5+1,startBadIndex=-1,endBadIndex=-1,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxElement)
            {
               maxElement = nums[i];
            }
            else if(nums[i]<maxElement)
            {
                endBadIndex = i;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<minElement)
            {
               minElement = nums[i];
            }
            else if(nums[i]>minElement)
            {
                startBadIndex = i;
            }
        }
        
        // cout<<endBadIndex<<" "<<startBadIndex<<"\n";
        if(startBadIndex==-1 || endBadIndex==-1)
            return 0;
        else
            return abs(endBadIndex-startBadIndex)+1;
    }
};

// 2 6 7 8 3 4 5 10 1 9
// start from left keep track of max element & if any element smaller than max found its the bad element
    
    
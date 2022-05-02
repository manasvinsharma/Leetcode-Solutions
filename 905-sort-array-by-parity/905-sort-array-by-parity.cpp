class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if((nums[i]&1) && !(nums[j]&1))
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            
            if(!(nums[i]&1))
                i++;
            
            if(nums[j]&1)
                j--;
        }
        
        return nums;
    }
};
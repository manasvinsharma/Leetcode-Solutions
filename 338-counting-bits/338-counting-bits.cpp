class Solution {
public:
    vector<int> countBits(int &n) {
        vector<int>ans(n+1,0);
        ans[0]=0;
        if(n==0)
            return ans;
        
        ans[1]=1;
        if(n==1)
            return ans;
        
        ans[2]=1;
        if(n==2)
            return ans;
        
        for(int i=3;i<=n;i++)
        {
            if(i&1)
            {
                ans[i] = ans[i/2] + 1;
            }
            else
            {
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};

// Method-2
// class Solution {
// public:
//     // helper function to count set bits
//     int CountOnes(int num)
//     {
//         int ones=0;
//         for(int i=0;i<32;i++)
//         {
//             if(1<<i&num)
//                 ones++;
//         }
//         return ones;
//     }
    
//     vector<int> countBits(int &n) {
//         vector<int>ans(n+1);
//         // O(32*n)
//         for(int i=0;i<=n;i++)
//         {
//             ans[i] = CountOnes(i); // CountOnes take O(32) constant time
//         }
//         return ans;
//     }
// };
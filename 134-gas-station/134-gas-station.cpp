class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0, totalCost=0, bal=0, p=0, n=gas.size(), ans=0;
        
        // find sum of total gas
        for(int x : gas)
            totalGas+=x;
        
        // find sum of total cost
        for(int x : cost)
            totalCost+=x;
        
        // if totalGas is less than totalCost then its not possible
        if(totalGas<totalCost)
            return -1;
        
        // p pointer points to current index
        while(p < n)
        {
            // if possible to move from p index
            if(bal+gas[p] >= cost[p])
            {
                bal = bal+gas[p]-cost[p];
                p++;
            }
            else
            {
                p++;
                bal=0;
                // update ans
                ans=p;
            }
        }
        
        return ans;
    }
};

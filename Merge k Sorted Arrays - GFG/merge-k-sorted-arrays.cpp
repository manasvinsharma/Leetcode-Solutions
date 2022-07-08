// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
class Three
{
  public:
  int val, row, col;
  
  Three(int val, int row, int col)
  {
      this->val = val;
      this->row = row;
      this->col = col;
  }
};

// comparator fnx in heap works opposite to that of sorting
struct Compare {
    bool operator()(Three const& a, Three const& b)
    {
        // this will keep smaller value ie b at top of min heap
        return a.val > b.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        int m = arr.size(), n = arr[0].size(), i=0, j=1;
        priority_queue <Three, vector<Three>, Compare> pq;
        vector<int>ans;
        
        for(int i=0;i<m;i++)
        {
            Three x = Three(arr[i][0],i,0);
            pq.push(x);
        }
        
        while(!pq.empty())
        {
            Three x = pq.top();
            pq.pop();
            
            ans.push_back(x.val);
            
            int row = x.row, col = x.col;
            
            if(col<n-1)
            {
                col++;
                Three y = Three(arr[row][col], row, col);
                pq.push(y);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends
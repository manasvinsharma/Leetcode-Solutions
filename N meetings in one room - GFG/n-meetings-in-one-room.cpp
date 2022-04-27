// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int a1[], int a2[], int n)
    {
        // Your code here
        vector<pair<int,int>>arr(n);
        int start,end,count=0;
        
        for(int i=0;i<n;i++)
        {
            arr[i] = {a1[i],a2[i]};
        }
        
        sort(arr.begin(),arr.end());
        start = arr[0].first, end = arr[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i].first >= start && arr[i].first<=end)
            {
                if(arr[i].second<end)
                {
                    start = arr[i].first;
                    end = arr[i].second;
                }
                count++;
            }
            else
            {
                start = arr[i].first;
                end = arr[i].second;
            }
        }
        
        return n-count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Node
{
    public:
    int freq;
    char ch;
    Node *left, *right; 
    
    Node()
    {
        freq = -1;
        left = NULL;
        right = NULL;
    }
    
    Node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
	    public:
	    vector<string>ans;
	
	    struct Comp{
            bool operator()(Node *a,Node *b){
                return a->freq > b->freq;
            }
        };
    
        
        void preorder(Node *root, string path)
        {
            if(!root)
            return ;
            
            if(!root->left && !root->right)
            {
                ans.push_back(path);
                return ;
            }
            
            preorder(root->left, path+"0");
            preorder(root->right, path+"1");
            return ;
        }
    
		vector<string> huffmanCodes(string s,vector<int> &f,int n)
		{
		    // Code here
		    priority_queue<Node*, vector<Node*>, Comp> pq;
		    Node* root = NULL;
		    
		    for(int i=0;i<n;i++)
		    {
		        Node *newNode = new Node(s[i], f[i]);
		        pq.push(newNode);
		    }
		    
		    while(pq.size()>=2)
		    {
		        Node *firstNode = pq.top();
		        int freq1 = firstNode->freq;
		        
		        pq.pop();
		        
		        Node* secondNode = pq.top();
		        int freq2 = secondNode->freq;
		        
		        pq.pop();
		        
		        Node* newNode = new Node('*', freq1+freq2);
		        
		        if(freq1<=freq2)
		        {
		            newNode->left = firstNode;
		            newNode->right = secondNode;
		        }
		        else
		        {
		            newNode->right = firstNode;
		            newNode->left = secondNode;
		        }
		        
		        pq.push(newNode);
		        
		        root = newNode;
		    }
		    
		    preorder(root, "");
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
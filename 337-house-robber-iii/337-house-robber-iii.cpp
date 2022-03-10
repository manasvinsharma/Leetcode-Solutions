/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // We will traverse in Postorder format (bottom to up)
    // For each node we will return a pair{include val, exclude val}
    // if we include a node in our answer then we cant include any of its childs
    // if we dont include a node in our answer then can take or not take any of its child
    
    pair<int,int> solve(TreeNode* root)
    {
        if(!root)
            return {0,0};
        
        pair<int,int>l = solve(root->left);
        pair<int,int>r = solve(root->right);

        // if we include a node in our answer then we cant include any of its childs
        int inc = l.second + r.second + root->val;
        // if we dont include a node in our answer then can take or not take any of its child
        int exc = max(l.first,l.second) + max(r.first,r.second);
        
        return {inc,exc};
    }
    
    int rob(TreeNode* root) {
        pair<int,int>ans = solve(root);
        return max(ans.first,ans.second);
    }
};
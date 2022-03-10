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
    pair<int,int> solve(TreeNode* root)
    {
        if(!root)
            return {0,0};
        
        pair<int,int>l = solve(root->left);
        pair<int,int>r = solve(root->right);
        
        int inc = l.second + r.second + root->val;
        int exc = max(l.first,l.second) + max(r.first,r.second);
        
        return {inc,exc};
    }
    
    int rob(TreeNode* root) {
        pair<int,int>ans = solve(root);
        return max(ans.first,ans.second);
    }
};
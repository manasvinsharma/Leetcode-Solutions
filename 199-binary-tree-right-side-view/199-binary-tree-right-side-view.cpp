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

// This question can also be done using level order traversal (using queue) 
class Solution {
public:
    vector<int>ans;
    
    // preorder traversal
    void solve(TreeNode* root, int level)
    {
        if(!root)
            return ;
        
        // if ans has no element from current level, then take current root value as it is the first from right side at this level
        // size of ans vector corresponds to current level of tree
        if(level==ans.size()+1)
        {
            ans.push_back(root->val);
        }
        
        // visit right first (main logic)
        solve(root->right,level+1);
        // then visit left
        solve(root->left,level+1);
        return ;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        // consider root at level 1
        solve(root,1);
        return ans;
    }
};
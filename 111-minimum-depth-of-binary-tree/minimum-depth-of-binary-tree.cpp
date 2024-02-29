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
    void solve(TreeNode* root,int &ans,int temp){
        if(root==NULL)
        return ;
       
        if(root->left==NULL && root->right==NULL){
            ans=min(ans,temp);
            temp=0;
        }
        temp++;
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);
        return ;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        int ans=INT_MAX;
        int temp=1;
        solve(root,ans,temp);
        return ans;
    }
};
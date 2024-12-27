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
    int longestPathCalculation(TreeNode *root, int &maxi){
        if(root==NULL) return 0;
        int leftPath=longestPathCalculation(root->left, maxi);
        int rightPath=longestPathCalculation(root->right, maxi);
        int left=0, right=0;
        if(root->left!=NULL && root->left->val==root->val) left=leftPath+1;
        if(root->right!=NULL && root->right->val==root->val) right=rightPath+1;
        maxi=max(maxi, left+right);
        return max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        longestPathCalculation(root, maxi);
        return maxi;
    }
};
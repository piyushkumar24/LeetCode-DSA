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
int ans=0;
    void helper(TreeNode *root, int targetSum, long long sum){
        if(root==NULL) return;
        sum+=root->val;
        if(sum==targetSum) ans++;
        helper(root->left, targetSum, sum);
        helper(root->right, targetSum, sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        helper(root, targetSum, 0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};
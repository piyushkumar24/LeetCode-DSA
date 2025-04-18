/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case
        if(root==NULL || root==p || root==q) return root;
        TreeNode *left=lowestCommonAncestor(root->left, p, q);
        TreeNode *right=lowestCommonAncestor(root->right, p, q);
        // Result
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root; // Both left and right are not null, we found our result
    }
};
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
    int Diameter(TreeNode *root, int &maxi){
        if(root==NULL) return 0;
        int lh=Diameter(root->left, maxi);
        int rh=Diameter(root->right, maxi);
        maxi=max(maxi, lh+rh);
        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        Diameter(root, maxi);
        return maxi;
    }
};
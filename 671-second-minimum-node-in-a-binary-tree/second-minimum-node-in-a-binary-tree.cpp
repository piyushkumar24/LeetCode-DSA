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
    long long firstMin, secondMin=LONG_MAX;
    void findSecMin(TreeNode *root){
        if(root==NULL) return;
        if(root->val > firstMin && root->val < secondMin) secondMin=root->val;
        findSecMin(root->left);
        findSecMin(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        firstMin=root->val;
        findSecMin(root);
        if(secondMin==LONG_MAX) return -1;
        return secondMin;
    }
};
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
    void inorder(TreeNode *node, int &cnt, int k, int &kSmallest){
        if(node==NULL || cnt>=k) return;
        inorder(node->left, cnt, k, kSmallest);
        cnt++;
        if(cnt==k){
            kSmallest=node->val;
            return;
        }
        inorder(node->right, cnt, k, kSmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest=INT_MAX;
        int cnt=0;
        inorder(root, cnt, k, kSmallest);
        return kSmallest;
    }
};
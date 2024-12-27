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
    int camera=0;
    int helper(TreeNode *root){
        // Helper function defines three states:(-1,0,1)
        // -1 : If you are already covered
        // 0 : You have a camera
        // 1 : If you need a Camera
        if(root==NULL) return 0;
        int lchild=helper(root->left);
        int rchild=helper(root->right);
        if(lchild==1 || rchild==1){
            camera++;
            return -1;
        }
        if(lchild==-1 || rchild==-1) return 0;
        else return 1;
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root)==1) camera++;
        return camera;
    }
};
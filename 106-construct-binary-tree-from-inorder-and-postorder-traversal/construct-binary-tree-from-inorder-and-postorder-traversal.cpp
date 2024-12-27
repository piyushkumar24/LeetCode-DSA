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
    TreeNode *build(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, map<int, int>&mpp){
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode *root=new TreeNode(postorder[postEnd]);
        int rootPos=mpp[postorder[postEnd]];
        int leftNums=rootPos-inStart;
        root->left=build(inorder, inStart, rootPos-1, postorder, postStart, postStart+leftNums-1, mpp);
        root->right=build(inorder, rootPos+1, inEnd, postorder, postStart+leftNums, postEnd-1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int, int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode *root=build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
        return root;
    }
};
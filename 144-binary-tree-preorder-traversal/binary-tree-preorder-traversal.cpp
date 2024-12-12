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


// RECURSIVE APPROACH:

// class Solution {
// public:
//     void Preorder(TreeNode *root,vector<int>&result){
//         if(root==NULL) return;
//         result.push_back(root->val);
//         Preorder(root->left,result);
//         Preorder(root->right,result);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         Preorder(root,ans);
//         return ans;
//     }
// };




// ITERATIVE APPROACH:

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>Preorder;
        if(root==NULL) return Preorder;
        stack<TreeNode *>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            Preorder.push_back(root->val);
            if(root->right!=NULL) st.push(root->right);
            if(root->left!=NULL) st.push(root->left);
        }
        return Preorder;
    }
};
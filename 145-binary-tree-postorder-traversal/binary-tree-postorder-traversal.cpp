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
//     void Postorder (TreeNode *root,vector<int>&ans){
//         if(root==NULL) return;
//         Postorder(root->left,ans);
//         Postorder(root->right,ans);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         Postorder(root,ans);
//         return ans;
//     }
// };





// ITERATIVE APPROACH USING 2 STACKS:

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>postorder;
//         if(root==NULL) return postorder;
//         stack<TreeNode *>st1,st2;
//         st1.push(root);
//         while(!st1.empty()){
//             root=st1.top();
//             st1.pop();
//             st2.push(root);
//             if(root->left!=NULL) st1.push(root->left);
//             if(root->right!=NULL) st1.push(root->right);
//         }
//         while(!st2.empty()){
//             postorder.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return postorder;
//     }
// };





// ITERATIVE APPROACH USING 1 STACK:

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>Postorder;
        if(root==NULL) return Postorder;
        stack<TreeNode*>st;
        while(root!=NULL || !st.empty()){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode *temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    Postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        Postorder.push_back(temp->val);
                    }
                }
                else root=temp;
            }
        }
        return Postorder;
    }
};
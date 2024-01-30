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
//         if(root==NULL){
//             return;
//         }
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
//         vector<int>ans;
//         if(root==NULL){
//             return ans;
//         }
//         stack <TreeNode *>s1;
//         stack <TreeNode *>s2;
//         s1.push(root);
//         while(!s1.empty()){
//             root=s1.top();
//             s1.pop();
//             s2.push(root);
//             if(root->left!=NULL){
//                 s1.push(root->left);
//             }
//             if(root->right!=NULL){
//                 s1.push(root->right);
//             }
//         }
//         while(!s2.empty()){
//             ans.push_back(s2.top()->val);
//             s2.pop();
//         }
//         return ans;
//     }
// };





// ITERATIVE APPROACH USING 1 STACK:

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode *>s;
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode *temp=s.top() ->right;
                if(temp==NULL){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    root=temp;
                }
            }
        }
        return ans;
    }
};
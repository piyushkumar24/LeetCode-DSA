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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;  // If the tree is empty, return depth 0
        queue<pair<TreeNode*,int>> q;  // Queue to store nodes along with their depth
        q.push({root,1});  // Start with the root node at depth 1
        while(!q.empty()) {
            auto [node,depth] = q.front();  // Get the front node and its depth
            q.pop();
            // If this is a leaf node, return its depth
            if(node->left==NULL && node->right==NULL) return depth;
            // If there is a left child, add it to the queue with depth + 1
            if(node->left!=NULL) q.push({node->left,depth+1});
            // If there is a right child, add it to the queue with depth + 1
            if (node->right!=NULL) q.push({node->right,depth+1});
        }
        return 0;  // This line will never be reached if the tree is valid
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoRight = true;
        while (!q.empty()) {
            int width = q.size();
            vector<int> oneLevel(width);
            
            for (int i = 0; i < width; i++) {
                TreeNode* front = q.front();
            q.pop();
                int index;
                if (lefttoRight) {
                    index = i;
                } 
                else {
                    index = width - i - 1;
                }
                oneLevel[index]=front->val;
                if(front->left){
                   q.push(front->left);
                }
                if(front->right){
                   q.push(front->right);
                }
            }
            lefttoRight =!lefttoRight;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};
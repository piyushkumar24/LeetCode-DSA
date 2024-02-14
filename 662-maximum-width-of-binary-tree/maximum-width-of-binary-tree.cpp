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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxwidth=0;
        queue<pair<TreeNode*,int>> q; //[node,index]
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int refering_idx=q.front().second;
            int first,last; // to calculate the width
            for(int i=0;i<size;i++){
                int cur_idx=q.front().second-refering_idx; // in simplest form
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur_idx;
                if(i==size-1) last=cur_idx;
                if(node->left) q.push({node->left,(long long)cur_idx*2+1});
                if(node->right) q.push({node->right,(long long)cur_idx*2+2});
            }
            maxwidth=max(maxwidth,last-first+1);
        }
        return maxwidth;
    }
};
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

// class NodeValue{
// public:
//     int maxNode, minNode, maxSum;
//     NodeValue(int minNode, int maxNode, int maxSum){
//         this->maxNode=maxNode;
//         this->minNode=minNode;
//         this->maxSum=maxSum;
//     }
// };

// class Solution {
// private:
//     NodeValue maxSumBSTHelper(TreeNode *root, int &ans){
//         if(root==NULL) return NodeValue(INT_MAX, INT_MIN, 0);
//         auto left=maxSumBSTHelper(root->left, ans);
//         auto right=maxSumBSTHelper(root->right, ans);
//         if(left.maxNode < root->val && root->val < right.minNode){
//             int ans = root->val + left.maxSum + right.maxSum;
//             return NodeValue(min(root->val,left.minNode), max(root->val,right.maxNode) , max(ans, root->val+left.maxSum+right.maxSum));
//         }
//         return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
//     }
// public:
//     int maxSumBST(TreeNode* root){
//         int ans=0;
//         maxSumBSTHelper(root, ans);
//         return ans;
//     }
// };

class NodeValue {
public:
    int maxNode, minNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
};

class Solution {
private:
    NodeValue maxSumBSTHelper(TreeNode *root, int &ans) {
        if (root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = maxSumBSTHelper(root->left, ans);
        auto right = maxSumBSTHelper(root->right, ans);
        if (left.maxNode < root->val && root->val < right.minNode) {
            int currentSum = root->val + left.maxSum + right.maxSum;
            ans = max(ans, currentSum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), currentSum);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        maxSumBSTHelper(root, ans);
        return ans;
    }
};
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
    bool balance = true;
    int getHeight(TreeNode *root){
        if(!root)   return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if(abs(left-right) > 1) balance = false;
        return max(left,right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return balance;
    }
};
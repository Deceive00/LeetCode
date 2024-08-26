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
    int maxHeight = -1;
    int getHeight(TreeNode* curr){
        if(!curr){
            return 0;
        }

        int left = getHeight(curr->left);
        int right = getHeight(curr->right);

        return 1 + max(left, right);
    }
    void getDiameter(TreeNode *root){
        if(!root)   return;
        getDiameter(root->left);
        getDiameter(root->right);
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int length = left + right;
        if(length > maxHeight){
            maxHeight = length;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);
        return maxHeight;
    }
};
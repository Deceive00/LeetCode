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
    vector<int> sorted;
    void inOrder(TreeNode *curr){
        if(!curr)   return;
        inOrder(curr->left);
        sorted.push_back(curr->val);
        inOrder(curr->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        inOrder(root);
        for(int i = 0 ; i < sorted.size() - 1 ; i++){
            if(sorted[i] >= sorted[i + 1]){
                return false;
            }
        }

        return true;
    }
};
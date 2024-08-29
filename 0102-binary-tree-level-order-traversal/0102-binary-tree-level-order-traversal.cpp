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
    vector<vector<int>> vec;

    void traverse(TreeNode *curr, int i){
        if(curr == nullptr)   return;
        if(i >= vec.size()) {
            vec.push_back(vector<int>());
        }

        vec[i].push_back(curr->val);
        
        traverse(curr->left, i + 1);
        traverse(curr->right, i + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        traverse(root, 0);
        return vec;
    }
};
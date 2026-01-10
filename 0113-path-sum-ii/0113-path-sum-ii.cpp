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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int targetSum, vector<int> vec) {
        if (!root) return;
        vec.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(vec);
        }

        dfs(root->left, targetSum - root->val, vec);
        dfs(root->right, targetSum - root->val, vec);

        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, {});
        return res;
    }
};
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
    vector<vector<int>> map;
    void pre(TreeNode *curr, int i){
        if(!curr)   return;
        if(i >= map.size()) {
            map.push_back(vector<int>());
        }
        pre(curr->left, i + 1);
        map[i].push_back(curr->val);
        pre(curr->right, i + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> vec;
        pre(root, 0);
        for(vector<int> v : map){
            vec.push_back(v[v.size() - 1]);
        }
        return vec;
    }
};
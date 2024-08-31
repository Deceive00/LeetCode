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
    int counter = 0;
    void traverse(TreeNode *curr, int max){
        if(!curr)   return;
        cout << curr->val << " " << max << endl;
        if(max <= curr->val){
            max = curr->val;
            counter++;
        }

        traverse(curr->left, max);
        traverse(curr->right, max);
    }
    int goodNodes(TreeNode* root) {
        traverse(root, -10001);
        return counter;
    }
};
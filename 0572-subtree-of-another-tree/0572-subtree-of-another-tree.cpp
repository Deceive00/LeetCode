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
    bool isSameTree(TreeNode *p,TreeNode *q){
        if(p && !q) {
            return false;
        }
        else if(!p && q){
            return false;
        } 
        else if(!p && !q){
            return true;
        }

        bool left = false;
        bool right = false;
        if(p->val != q->val)    return false;
        left = isSameTree(p->left, q->left);
        right = isSameTree(p->right, q->right);

        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return false;
        if(!root)   return false;
        if(isSameTree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
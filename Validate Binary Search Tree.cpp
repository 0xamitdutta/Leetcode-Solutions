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
 
// Do not check left and right child. Instead check for range in (min, max)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long int min, long int max){
        if(!root) return true;
        if(root->val <= min) return false;
        if(root->val >= max) return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

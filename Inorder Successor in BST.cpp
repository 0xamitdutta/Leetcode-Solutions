// https://www.lintcode.com/problem/inorder-successor-in-bst/description

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(!root) return NULL;
        
        // Case 1 : Rigt subtree exists
        if(p->right)
            return findMin(p->right);
        
        // Case 2 : Right subree doesn't exists
        // We want to find deepest node from root to p for which p lies in the left
        TreeNode* successor = NULL;
        TreeNode* ancestor = root;
        while(ancestor != p){
            if(p->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
    
    TreeNode* findMin(TreeNode* root){
        if(!root->left) return root;
        root = root->left;
    }
};

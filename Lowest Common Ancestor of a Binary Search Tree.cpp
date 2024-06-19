/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//RECURSIVE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

//ITERATIVE
// Use top-down dfs for this and bottom-up dfs for bt
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        
        TreeNode* curr = root;
        while(curr != NULL){
            int val = curr->val;
            if(p->val < val && q->val < val)
                curr = curr->left;
            else if(p->val > val && q->val > val)
                curr = curr->right;
            else
                return curr;
        }
        return NULL;
    }
};

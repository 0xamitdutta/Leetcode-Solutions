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
    struct BSTpair{
        bool isBST;
        int minm;
        int maxm;
        int size;
        isBSTpair() : isBST(true), minm(INT_MAX), maxm(INT_MIN), size(0) {}
    };
public:
    bool isValidBST(TreeNode* root) {
        BSTpair bp = isBST(root);
        return bp.size();
    }
    
    BSTpair isBST(TreeNode* root){
        if(!root){
            BSTpair bp;
            return bp;
        }
        
        BSTpair lp = isBST(root->left);
        BSTpair rp = isBST(root->right);
        BSTpair cp;
        cp.isBST = lp.isBST && rp.isBST && (root->val > lp.maxm && root->val < rp.minm);
        
        cp.minm = min(root->val, min(lp.minm, rp.minm));
        cp.maxm = max(root->val, max(lp.maxm, rp.maxm));
        
        if(cp.isBST) cp.size = lp.size + rp.size + 1;
        else if(lp.size > rp.size) cp.size = lp.size;
        else cp.size = rp.size;
    }
};

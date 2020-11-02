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
// Top-Down
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

// Bottom-Up (Useful for similar Question : Largest BST in a Binary Tree)
class Solution {
    struct BSTpair{
        bool isBST;
        int minm;
        int maxm;
        isBSTpair() : isBST(true), minm(INT_MAX), maxm(INT_MIN) {}
    };
public:
    BSTpair isBST(root){
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
        return cp;
    }
    
    bool isValidBST(TreeNode* root) {
        BSTpair bp = isBST(root);
        return bp.isBST;
    }
};

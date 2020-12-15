// https://www.lintcode.com/problem/lowest-common-ancestor-iii/description
// Uses Bottom Up recursion rather than the normal Top Down way

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    bool foundA = false, foundB = false;
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        auto lca = helper(root, A, B);
        if(foundA && foundB) 
            return lca;
        return NULL;
    }
    
    TreeNode* helper(TreeNode * root, TreeNode * A, TreeNode * B){
        if(!root) return NULL;
        
        auto l = helper(root->left, A, B);
        auto r = helper(root->right, A, B);
        
        if(root == A) {
            foundA = true;
            return root;
        }
        if(root == B) {
            foundB = true;
            return root;
        }
        if(l && r) return root;
        return l != NULL ? l : r;
    }
};

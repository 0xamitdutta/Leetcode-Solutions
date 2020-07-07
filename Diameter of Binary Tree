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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int dmt = 0;
        helper(root, dmt);
        return dmt;
    }
    
    int helper(TreeNode* root, int& dmt){
        if(!root) return;
        
        int left = helper(root->left, dmt);
        int right = helper(root->right, dmt);
        dmt = max(dmt, left+right);     // Diameter may or may not pass through it. Hence max() for both possibility
        return max(left, right) + 1;    // Return longest lenth path through it
    }
};

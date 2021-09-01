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
    int getLevel(TreeNode* root) {
        if(!root) return -1;
        return 1 + getLevel(root->left);
    }
    
    int countNodes(TreeNode* root) {
        int level = getLevel(root);
        
        if(level < 0) return 0;
        return getLevel(root->right) == level-1 ? (1 << level) + countNodes(root->right) : (1 << level-1) + countNodes(root->left);
    }
};

// Number of Nodes in Left Subtree = GP formula = 2^n - 1 = 2^level - 1. -1 is gone because of +1 at root.
// Number of Nodes in Right Subtree = GP formula = 2^n - 1 = 2^level-1 - 1. -1 is gone because of +1 at root.

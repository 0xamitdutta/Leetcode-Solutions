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
 
// Time Complexity : O(n*n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(calculateHeight(root->left) - calculateHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int calculateHeight(TreeNode* root){
        if(!root) return 0;
        return max(calculateHeight(root->left), calculateHeight(root->right)) + 1;
    }
};

// Time Complexity : O(n)
class Solution {
public:
    bool balanced = true; // Use a global varibale to cut down 2 recursions to only 1 recursion
    bool isBalanced(TreeNode* root) {
        helper(root, balanced);
        return balanced;
    }
    
    int helper(TreeNode* root, bool& balanced){
        if(!root) return 0;
        int left = helper(root->left, balanced);
        int right = helper(root->right, balanced);
        if(abs(left - right) > 1) balanced = false;
        return max(left, right) + 1;
    }
};

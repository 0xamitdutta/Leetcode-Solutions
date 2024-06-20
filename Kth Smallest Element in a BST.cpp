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
    int ans = 0;
    int kthSmallest(TreeNode* root, int K) {
        inorder(root, K);
        return ans;
    }
    
    void inorder(TreeNode* root, int& K) {
        if(!root || !K) return;
        inorder(root->left, K);
        if(--K == 0) {
            ans = root->val;
            return;
        }   
        inorder(root->right, K);
    }
};

// Iterative
// We can use inorder traversal also to create a sorted array. But doing iteratively with stack will only process k elements.
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Recursive
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
    
    int helper(TreeNode* root, int &k){
        // k == 0 is for if we found the ans on left we do not want to waste our time on right.
        if(root == NULL || k == 0) return -1;
        
        int left = helper(root->left, k);
        if(--k == 0) return root->val;
        int right = helper(root->right, k);
        return left != -1 ? left : right;
    }
};

// Iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // We can use inorder traversal also to create a sorted array. But doing iteratively with stack will only process k elements.
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr != NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                curr = s.top();
                s.pop();
                if(--k == 0)
                    return curr->val;
                curr = curr->right;
            }
        }
        return -1;
    }
};

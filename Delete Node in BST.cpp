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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case1: Leaf Node
            if(!root->left && !root->right)
                return NULL;
            // Case2: No left subtree (Return right subtree)
            if(!root->left)
                return root->right;
            // Case3: No right subtree (Return left subtree)
            if(!root->right)
                return root->left;
            // Case4: Contains left and right subtree 
            // (Replace root's value with min value in right subtree and then delete that minValue OR Replace root's value with max value in left subtree and then delete that maxValue)
            TreeNode* minNode = findMinNode(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }

    TreeNode* findMinNode(TreeNode* root) {
        while(root->left) {
            root = root->left;
        }
        return root;
    }
};

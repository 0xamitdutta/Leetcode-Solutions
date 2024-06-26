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
 
// Make sure to pass the index by reference
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        int index = 0;
        return helper(preorder, index, INT_MAX);
    }
    
    TreeNode* helper(vector<int>& preorder, int& index, int limit){
        if(index == preorder.size() || preorder[index] > limit) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        
        // Just think about the upper bound rest is easy
        root->left = helper(preorder, index, root->val);
        root->right = helper(preorder, index, limit);
        return root;
    }
};

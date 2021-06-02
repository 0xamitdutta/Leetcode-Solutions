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
    unordered_map<TreeNode*, int> m; // HashMap to memoise answers previously calculated
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(m.count(root)) return m[root];
        
        int ans = root->val;
        if(root->left != NULL)
            ans += rob(root->left->left) + rob(root->left->right);
        if(root->right != NULL)
            ans += rob(root->right->left) + rob(root->right->right);
        return m[root] = max(ans, rob(root->left) + rob(root->right));
    }
};

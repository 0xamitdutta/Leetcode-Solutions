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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum, {});
        return res;
    }
    
    void dfs(TreeNode* root, int sum, int& targetSum, vector<int> curr) {
        if(!root) return;
        
        sum += root->val;
        curr.push_back(root->val);
        if(!root->left && !root->right && sum == targetSum){
            res.push_back(curr);
            return;
        }
        
        dfs(root->left, sum, targetSum, curr);
        dfs(root->right, sum, targetSum, curr);
    }
};

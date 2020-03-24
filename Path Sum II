/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        vector<int> curr;
        countPath(root, sum, curr, res);
        return res;
    }
    
    void countPath(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& res){
        if(root == NULL)
            return;
        
        curr.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum)
            res.push_back(curr);
        
        countPath(root->left, sum-root->val, curr, res);
        countPath(root->right, sum-root->val, curr, res);
        curr.pop_back();
    }
};

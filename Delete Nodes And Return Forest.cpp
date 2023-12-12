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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // We use unordered set to do a quick search whether a node value is present or not in the list. It will be O(1) time to do a scan.
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        dfs(root, toDeleteSet, forest);
        if(!toDeleteSet.count(root->val))
            forest.push_back(root);
        return forest;
    }

    TreeNode* dfs(TreeNode* root, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if(!root) return NULL;

        root->left = dfs(root->left, toDeleteSet, forest);
        root->right = dfs(root->right, toDeleteSet, forest);

        // If a node has to be deleted, we need to return NULL to its parent. Also we need to add its left and right subtree to the forest
        if(toDeleteSet.count(root->val)) {
            if(root->left) 
                forest.push_back(root->left);
            if(root->right)
                forest.push_back(root->right);
            return NULL;
        }
        return root;
    }
};

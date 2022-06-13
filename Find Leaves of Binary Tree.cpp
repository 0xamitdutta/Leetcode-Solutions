/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    map<int, vector<int>> m;
    vector<vector<int>> findLeaves(TreeNode * root) {
        findLeavesHelper(root, 0);
        vector<vector<int>> res;
        for(auto key : m)
            res.push_back(key.second);
        return res;
    }

    int findLeavesHelper(TreeNode* root, int level) {
        if(!root) return 0;
        
        // Postorder DFS Traversl along with keeping a Level check
        int l = findLeavesHelper(root->left, level);
        int r = findLeavesHelper(root->right, level);
        level = max(l, r);
        m[level].push_back(root->val);
        return level + 1;
    }
};

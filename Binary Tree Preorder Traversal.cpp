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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr != NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);
                res.push_back(curr->val);
                curr = curr->left;
            }
            else{
                curr = s.top();
                s.pop();
                curr = curr->right;
            }
        }
        return res;
    }
};

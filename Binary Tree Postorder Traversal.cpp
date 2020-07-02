/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Method 1 : Reverse
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr != NULL || !s.empty()){
            while(curr != NULL){
                s.push(curr);
                res.push_back(curr->val);
                curr = curr->right;
            }
            curr = s.top();
            s.pop();
            curr = curr->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//Method 2 : Using a prev pointer
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root, *prev = NULL;
        while(curr != NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                curr = s.top();
                if(curr->right && curr->right != prev)
                    curr = curr->right;
                else{
                    s.pop();
                    res.push_back(curr->val);
                    prev = curr;
                    curr = NULL;
                }
            }
        }
        return res;
    }
};

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
 
// With Queue
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> curr(size);
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                int index = left_to_right ? i : size-1-i;
                curr[index] = temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(curr);
            left_to_right = !left_to_right;
        }
        return res;
    }
};

// With 2 Stacks
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        stack<TreeNode*> curr;
        stack<TreeNode*> next; 
        curr.push(root);
        bool left_to_right = true;
        while(!curr.empty()){
            int size = curr.size();
            vector<int> v;
            for(int i = 0; i < size; i++){
                TreeNode* temp = curr.top();
                curr.pop();
                v.push_back(temp->val);
                if(left_to_right){
                    if(temp->left) next.push(temp->left);
                    if(temp->right) next.push(temp->right);
                }
                else{
                    if(temp->right) next.push(temp->right);
                    if(temp->left) next.push(temp->left);
                }
            }
            res.push_back(v);
            swap(curr, next);
            left_to_right = !left_to_right;
        }
        return res;
    }
};


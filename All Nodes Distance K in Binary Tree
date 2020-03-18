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
    vector<int> distanceK(TreeNode* root, TreeNode* start, int K) {
        unordered_map<TreeNode*, TreeNode*> m;
        unordered_set<TreeNode*> s;
        initialise(m, root, NULL);
        
        int layer = 0;
        queue<TreeNode*> q;
        vector<int> res;
        q.push(start);
        s.insert(start);
        while(!q.empty()){
            if(layer == K)
                return printlayer(res, q);
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && s.find(curr->left) == s.end()){
                    q.push(curr->left);
                    s.insert(curr->left);
                }
                if(curr->right && s.find(curr->right) == s.end()){
                    q.push(curr->right);
                    s.insert(curr->right);
                }
                if(m[curr] && s.find(m[curr]) == s.end()){
                    q.push(m[curr]);
                    s.insert(m[curr]);
                }
            }
            layer++;
        }
        return res;
    }
        
    void initialise(unordered_map<TreeNode*, TreeNode*>& m, TreeNode* child, TreeNode* parent){
        if(child == NULL)
            return;

        m[child] = parent;
        initialise(m, child->left, child);
        initialise(m, child->right, child);
    }
        
    vector<int> printlayer(vector<int>& res, queue<TreeNode*>& q){
        while(!q.empty()){
            TreeNode* node = q.front();
            res.push_back(node->val);
            q.pop();
        }
        return res;
    }
};

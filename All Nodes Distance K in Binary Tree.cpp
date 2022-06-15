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
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> vis;
    vector<int> distanceK(TreeNode* root, TreeNode* start, int K) {
        initialiseParent(root, NULL);
        
        queue<TreeNode*> q;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
            if(K == 0)
                return printlayer(q);
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis.count(curr->left)){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && !vis.count(curr->right)){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(parents[curr] && !vis.count(parents[curr])){
                    q.push(parents[curr]);
                    vis.insert(parents[curr]);
                }
            }
            K--;
        }
        return vector<int>();
    }
        
    void initialiseParent(TreeNode* child, TreeNode* parent){
        if(!child) return;

        parents[child] = parent;
        initialiseParent(child->left, child);
        initialiseParent(child->right, child);
    }
        
    vector<int> printlayer(queue<TreeNode*>& q){
        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};

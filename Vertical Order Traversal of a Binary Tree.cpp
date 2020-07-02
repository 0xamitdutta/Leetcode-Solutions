// For FTF interviews Use This It does'nt values on the same level
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        calculateHorizontalDistance(root, q, m);
        for(auto [key, val] : m)
            res.push_back(val);
        return res;
    }
    
    void calculateHorizontalDistance(TreeNode* root, queue<pair<TreeNode*, int>> q, map<int, vector<int>>& m){
        if(root == NULL) return;
        
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            TreeNode* root = temp.first;
            int hd = temp.second;
            
            m[hd].push_back(root->val);
            if(root->left) q.push({root->left, hd-1});
            if(root->right) q.push({root->right, hd+1});
        }
    }
};

// Perfectly correct solution but difficult to implement. It uses the idea of co-ordinates x, y.
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

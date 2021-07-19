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
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
    unordered_map<TreeNode*, TreeNode*> m;
    TreeNode* start = NULL;
    int findClosestLeaf(TreeNode * root, int K) {
        mapParent(root, K, NULL);
        queue<TreeNode*> q;
        q.push(start);
        unordered_set<TreeNode*> s;
        s.insert(start);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(!node->left && !node->right) 
                return node->val;
            if(node->left && !s.count(node->left)) {
                q.push(node->left);
                s.insert(node->left);
            }
            if(node->right && !s.count(node->right)) {
                q.push(node->right);
                s.insert(node->right);
            }
            if(m[node] && !s.count(m[node])) {
                q.push(m[node]);
                s.insert(m[node]);
            }
        }
        return -1;
    }
  
    void mapParent(TreeNode* root, int& K, TreeNode* par) {
        if(!root) return;
        if(root->val == K) start = root;
        if(par) {
            m[root] = par;
        }
        mapParent(root->left, K, root);
        mapParent(root->right, K, root);
    }
};

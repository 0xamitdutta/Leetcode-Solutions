/* BFS solution in this much better performance wise as compared to DFS. Think of a tree having 500 left nodes and 1 right node.
   DFS will travel all the left nodes but BFS will stop after the minimum.
*/

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
 
// Take precautions of a skewed tree
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(!left) return right+1;
        if(!right) return left+1;
        return min(left, right)+1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(!temp->left && !temp->right)
                    return depth;
            }
        }
        return -1;
    }
};

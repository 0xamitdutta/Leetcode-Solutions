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
     //ITERATIVE SOLUTION
     bool isSymmetric(TreeNode* root){
         if(root == NULL)
             return true;

         queue<TreeNode*> q;
         q.push(root->left);
         q.push(root->right);
         while(!q.empty()){
             TreeNode* root1 = q.front();
             q.pop();
             TreeNode* root2 = q.front();
             q.pop();
             if(root1 == NULL && root2 == NULL)
                 continue;
             else if(root1 == NULL || root2 == NULL)
                 return false;
             else if(root1->val != root2->val)
                 return false;
             q.push(root1->left); q.push(root2->right);
             q.push(root1->right); q.push(root2->left);
         }
         return true;
     }
     
     
     //RECURSIVE SOLUTION
     bool isSymmetric(TreeNode* root) {
         if(root == NULL)
             return true;
        
         return checkSymmetry(root->left, root->right);
     }
    
     bool checkSymmetry(TreeNode* root1, TreeNode* root2){
         if(root1 == NULL && root2 == NULL)
             return true;
         else if(root1 == NULL || root2 == NULL)
             return false;
         else if(root1->val != root2->val)
             return false;
         return checkSymmetry(root1->left, root2->right) && checkSymmetry(root1->right, root2->left);
     }
};

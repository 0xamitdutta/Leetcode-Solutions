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
 
// Note : preStart, inStart, inEnd, inIndex. Use these variable at correct stage.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        return helper(0, 0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(inStart > inEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[preStart]){
                inIndex = i;
                break;
            }
        }
        root->left = helper(preStart+1, inStart, inIndex-1, preorder, inorder);
        root->right = helper(preStart+inIndex-inStart+1, inIndex+1, inEnd, preorder, inorder); // inIndex-inStart gives the size of left subtree
        return root;
    }
};

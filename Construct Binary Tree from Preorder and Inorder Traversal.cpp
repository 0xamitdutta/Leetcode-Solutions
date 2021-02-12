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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        return helper(0, 0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* helper(int preIndex, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preIndex > preorder.size()-1 || inStart > inEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preIndex]);
        int inIndex = 0;
        
        // Can also use a hashmap in the buildTree function to map inorder values with their index
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[preIndex]){
                inIndex = i;
                break;
            }
        }
        root->left = helper(preIndex+1, inStart, inIndex-1, preorder, inorder);
        root->right = helper(preIndex+inIndex-inStart+1, inIndex+1, inEnd, preorder, inorder);
        return root;
    }
};

/* 
Way to get Preorder's index in Right Subtree:
    Preorder Index + Elements in Left Subtree
    Preorder Index + (InIndex - InStart + 1)
*/

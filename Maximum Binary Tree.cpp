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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        
        return construct(nums, 0, nums.size()-1);
    }
    
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        
        int max_val = INT_MIN, index = left;
        for(int i = left; i <= right; i++){
            if(nums[i] > max_val){
                max_val = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(max_val);
        root->left = construct(nums, left, index-1);
        root->right = construct(nums, index+1, right);
        return root;
    }
};

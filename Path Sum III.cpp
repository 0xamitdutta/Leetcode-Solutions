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
 
// O(n^2)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int helper(TreeNode *root, int sum){
        if(!root) return 0;
        if(root->val == sum)
            return 1 + helper(root->left, sum-root->val) + helper(root->right, sum-root->val);
        return helper(root->left, sum-root->val) + helper(root->right, sum-root->val);
    }
};

// O(n)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        int ans  = 0;
        helper(root, sum, m, 0, ans);
        return ans;
    }
    
    void helper(TreeNode* root, int& sum, unordered_map<int, int>& m, int curr, int& ans){
        if(root == NULL) return;
        
        curr += root->val;
        if(m.find(curr-sum) != m.end())
            ans += m[curr-sum];
        m[curr]++;
        helper(root->left, sum, m, curr, ans);
        helper(root->right, sum, m, curr, ans);
        m[curr]--;
    }
};

/* If you observe closely you'll find this question is very similar to "Subarray sum Equals K"
   Hence If you have to count number of subarrays think of "Prefix Sum"
*/